/*
 * btn_drv.c
 *
 *  Created on: 3 nov. 2018
 *      Author: Emir Salihovic
 */
#include "../Inc/DriversHeader/btn_drv.h"

#define SD_DUMMY_BYTE            0xFF
#define SD_NO_RESPONSE_EXPECTED  0x80
#define HAL_SPI_MODULE_ENABLED

/**
  * @}
  */


/** @defgroup STM32F1XX_NUCLEO_Private_Variables STM32F1XX NUCLEO Private Variables
  * @{
  */
GPIO_TypeDef* LED_PORT[LEDn] = {LED2_GPIO_PORT};

const uint16_t LED_PIN[LEDn] = {LED2_PIN};

GPIO_TypeDef* BUTTON_PORT[BUTTONn]  = {USER_BUTTON_GPIO_PORT};
const uint16_t BUTTON_PIN[BUTTONn]  = {USER_BUTTON_PIN};
const uint8_t  BUTTON_IRQn[BUTTONn] = {USER_BUTTON_EXTI_IRQn };

/**
 * @brief BUS variables
 */

#ifdef HAL_SPI_MODULE_ENABLED
uint32_t SpixTimeout = NUCLEO_SPIx_TIMEOUT_MAX;        /*<! Value of Timeout when SPI communication fails */
static SPI_HandleTypeDef hnucleo_Spi;
#endif /* HAL_SPI_MODULE_ENABLED */


/**
  * @}
  */

/** @defgroup STM32F1XX_NUCLEO_Private_Functions STM32F1XX NUCLEO Private Functions
  * @{
  */
#ifdef HAL_SPI_MODULE_ENABLED
static void               SPIx_Init(void);
static void               SPIx_Write(uint8_t Value);
static void               SPIx_WriteData(uint8_t *DataIn, uint16_t DataLength);
static void               SPIx_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLegnth);
static void               SPIx_Error (void);
static void               SPIx_MspInit(void);

/* SD IO functions */
void                      SD_IO_Init(void);
void                      SD_IO_CSState(uint8_t state);
void                      SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength);
void                      SD_IO_ReadData(uint8_t *DataOut, uint16_t DataLength);
void                      SD_IO_WriteData(const uint8_t *Data, uint16_t DataLength);
uint8_t                   SD_IO_WriteByte(uint8_t Data);
uint8_t                   SD_IO_ReadByte(void);

/* LCD IO functions */
void                      LCD_IO_Init(void);
void                      LCD_IO_WriteData(uint8_t Data);
void                      LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size);
void                      LCD_IO_WriteReg(uint8_t LCDReg);
void                      LCD_Delay(uint32_t delay);
#endif /* HAL_SPI_MODULE_ENABLED */

/**
  * @}
  */

/** @defgroup STM32F1XX_NUCLEO_Exported_Functions STM32F1XX NUCLEO Exported Functions
  * @{
  */

/**
  * @brief  This method returns the STM32F1XX NUCLEO BSP Driver revision
  * @retval version : 0xXYZR (8bits for each decimal, R for RC)
  */

/** @defgroup STM32F1XX_NUCLEO_LED_Functions STM32F1XX NUCLEO LED Functions
  * @{
  */

/**
  * @brief  Configures LED GPIO.
  * @param  Led: Led to be configured.
  *          This parameter can be one of the following values:
  *     @arg LED2
  */
void BSP_LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  gpioinitstruct;

  /* Enable the GPIO_LED Clock */
  LEDx_GPIO_CLK_ENABLE(Led);

  /* Configure the GPIO_LED pin */
  gpioinitstruct.Pin    = LED_PIN[Led];
  gpioinitstruct.Mode   = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Pull   = GPIO_NOPULL;
  gpioinitstruct.Speed  = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(LED_PORT[Led], &gpioinitstruct);

  /* Reset PIN to switch off the LED */
  HAL_GPIO_WritePin(LED_PORT[Led],LED_PIN[Led], GPIO_PIN_RESET);
}

/**
  * @brief  DeInit LEDs.
  * @param  Led: LED to be de-init.
  *   This parameter can be one of the following values:
  *     @arg  LED2
  * @note Led DeInit does not disable the GPIO clock nor disable the Mfx
  */
void BSP_LED_DeInit(Led_TypeDef Led)
{
  GPIO_InitTypeDef  gpio_init_structure;

  /* Turn off LED */
  HAL_GPIO_WritePin(LED_PORT[Led],LED_PIN[Led], GPIO_PIN_RESET);
  /* DeInit the GPIO_LED pin */
  gpio_init_structure.Pin = LED_PIN[Led];
  HAL_GPIO_DeInit(LED_PORT[Led], gpio_init_structure.Pin);
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on.
  *   This parameter can be one of following parameters:
  *     @arg LED2
  */
void BSP_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}

/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off.
  *   This parameter can be one of following parameters:
  *     @arg LED2
  */
void BSP_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled.
  *   This parameter can be one of following parameters:
  *            @arg  LED2
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}

/**
  * @}
  */

/** @defgroup STM32F1XX_NUCLEO_BUTTON_Functions STM32F1XX NUCLEO BUTTON Functions
  * @{
  */

/**
  * @brief  Configures Button GPIO and EXTI Line.
  * @param  Button: Specifies the Button to be configured.
  *   This parameter should be: BUTTON_USER
  * @param  ButtonMode: Specifies Button mode.
  *   This parameter can be one of following parameters:
  *     @arg BUTTON_MODE_GPIO: Button will be used as simple IO
  *     @arg BUTTON_MODE_EXTI: Button will be connected to EXTI line with interrupt
  *                     generation capability
  */
void BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode)
{
  GPIO_InitTypeDef gpioinitstruct;

  /* Enable the BUTTON Clock */
  BUTTONx_GPIO_CLK_ENABLE(Button);

  gpioinitstruct.Pin = BUTTON_PIN[Button];
  gpioinitstruct.Pull = GPIO_NOPULL;
  gpioinitstruct.Speed = GPIO_SPEED_FREQ_MEDIUM;

  if (ButtonMode == BUTTON_MODE_GPIO)
  {
    /* Configure Button pin as input */
    gpioinitstruct.Mode   = GPIO_MODE_INPUT;

    HAL_GPIO_Init(BUTTON_PORT[Button], &gpioinitstruct);
  }

  if (ButtonMode == BUTTON_MODE_EXTI)
  {
    /* Configure Button pin as input with External interrupt */
    //gpioinitstruct.Mode   = GPIO_MODE_IT_FALLING;
    gpioinitstruct.Mode   = GPIO_MODE_IT_RISING;
    HAL_GPIO_Init(BUTTON_PORT[Button], &gpioinitstruct);

    /* Enable and set Button EXTI Interrupt to the lowest priority */
    HAL_NVIC_SetPriority((IRQn_Type)(BUTTON_IRQn[Button]), 0x0F, 0);
    HAL_NVIC_EnableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  }
}

/**
  * @brief  Push Button DeInit.
  * @param  Button: Button to be configured
  *   This parameter should be: BUTTON_USER
  * @note PB DeInit does not disable the GPIO clock
  */
void BSP_PB_DeInit(Button_TypeDef Button)
{
  GPIO_InitTypeDef gpio_init_structure;

  gpio_init_structure.Pin = BUTTON_PIN[Button];
  HAL_NVIC_DisableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  HAL_GPIO_DeInit(BUTTON_PORT[Button], gpio_init_structure.Pin);
}

/**
  * @brief  Returns the selected Button state.
  * @param  Button: Specifies the Button to be checked.
  *   This parameter should be: BUTTON_USER
  * @retval Button state.
  */
uint32_t BSP_PB_GetState(Button_TypeDef Button)
  {
  return HAL_GPIO_ReadPin(BUTTON_PORT[Button], BUTTON_PIN[Button]);
  }
/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup STM32F1XX_NUCLEO_Private_Functions
  * @{
  */

#ifdef HAL_SPI_MODULE_ENABLED
/******************************************************************************
                            BUS OPERATIONS
*******************************************************************************/
/**
  * @brief  Initialize SPI MSP.
  */
static void SPIx_MspInit(void)
{
  GPIO_InitTypeDef  gpioinitstruct = {0};

  /*** Configure the GPIOs ***/
  /* Enable GPIO clock */
  NUCLEO_SPIx_SCK_GPIO_CLK_ENABLE();
  NUCLEO_SPIx_MISO_MOSI_GPIO_CLK_ENABLE();

  /* Configure SPI SCK */
  gpioinitstruct.Pin        = NUCLEO_SPIx_SCK_PIN;
  gpioinitstruct.Mode       = GPIO_MODE_AF_PP;
  gpioinitstruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(NUCLEO_SPIx_SCK_GPIO_PORT, &gpioinitstruct);

  /* Configure SPI MISO and MOSI */
  gpioinitstruct.Pin        = NUCLEO_SPIx_MOSI_PIN;
  HAL_GPIO_Init(NUCLEO_SPIx_MISO_MOSI_GPIO_PORT, &gpioinitstruct);

  gpioinitstruct.Pin        = NUCLEO_SPIx_MISO_PIN;
  gpioinitstruct.Mode       = GPIO_MODE_INPUT;
  HAL_GPIO_Init(NUCLEO_SPIx_MISO_MOSI_GPIO_PORT, &gpioinitstruct);

  /*** Configure the SPI peripheral ***/
  /* Enable SPI clock */
  NUCLEO_SPIx_CLK_ENABLE();
}

/**
  * @brief  Initialize SPI HAL.
  */
static void SPIx_Init(void)
{
  if(HAL_SPI_GetState(&hnucleo_Spi) == HAL_SPI_STATE_RESET)
  {
    /* SPI Config */
    hnucleo_Spi.Instance = NUCLEO_SPIx;
      /* SPI baudrate is set to 8 MHz maximum (PCLK2/SPI_BaudRatePrescaler = 64/8 = 8 MHz)
       to verify these constraints:
          - ST7735 LCD SPI interface max baudrate is 15MHz for write and 6.66MHz for read
            Since the provided driver doesn't use read capability from LCD, only constraint
            on write baudrate is considered.
          - SD card SPI interface max baudrate is 25MHz for write/read
          - PCLK2 max frequency is 32 MHz
       */
    hnucleo_Spi.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_8;
    hnucleo_Spi.Init.Direction          = SPI_DIRECTION_2LINES;
    hnucleo_Spi.Init.CLKPhase           = SPI_PHASE_1EDGE;
    hnucleo_Spi.Init.CLKPolarity        = SPI_POLARITY_LOW;
    hnucleo_Spi.Init.CRCCalculation     = SPI_CRCCALCULATION_DISABLE;
    hnucleo_Spi.Init.CRCPolynomial      = 7;
    hnucleo_Spi.Init.DataSize           = SPI_DATASIZE_8BIT;
    hnucleo_Spi.Init.FirstBit           = SPI_FIRSTBIT_MSB;
    hnucleo_Spi.Init.NSS                = SPI_NSS_SOFT;
    hnucleo_Spi.Init.TIMode             = SPI_TIMODE_DISABLE;
    hnucleo_Spi.Init.Mode               = SPI_MODE_MASTER;

    SPIx_MspInit();
    HAL_SPI_Init(&hnucleo_Spi);
  }
}

/**
  * @brief  SPI Write a byte to device
  * @param  Value: value to be written
*/
static void SPIx_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_TransmitReceive(&hnucleo_Spi, (uint8_t*) DataIn, DataOut, DataLength, SpixTimeout);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }
}

/**
  * @brief  SPI Write an amount of data to device
  * @param  Value: value to be written
  * @param  DataLength: number of bytes to write
  */
static void SPIx_WriteData(uint8_t *DataIn, uint16_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_Transmit(&hnucleo_Spi, DataIn, DataLength, SpixTimeout);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }
}

/**
  * @brief  SPI Write a byte to device
  * @param  Value: value to be written
  */
static void SPIx_Write(uint8_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint8_t data;

  status = HAL_SPI_TransmitReceive(&hnucleo_Spi, (uint8_t*) &Value, &data, 1, SpixTimeout);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPIx_Error();
  }
}

/**
  * @brief  SPI error treatment function
  */
static void SPIx_Error (void)
{
  /* De-initialize the SPI communication BUS */
  HAL_SPI_DeInit(&hnucleo_Spi);

  /* Re-Initiaize the SPI communication BUS */
  SPIx_Init();
}

/******************************************************************************
                            LINK OPERATIONS
*******************************************************************************/

/********************************* LINK SD ************************************/
/**
  * @brief  Initialize the SD Card and put it into StandBy State (Ready for
  *         data transfer).
  */
void SD_IO_Init(void)
{
  GPIO_InitTypeDef  gpioinitstruct = {0};
  uint8_t counter = 0;

  /* SD_CS_GPIO Periph clock enable */
  SD_CS_GPIO_CLK_ENABLE();

  /* Configure SD_CS_PIN pin: SD Card CS pin */
  gpioinitstruct.Pin    = SD_CS_PIN;
  gpioinitstruct.Mode   = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Pull   = GPIO_PULLUP;
  gpioinitstruct.Speed  = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SD_CS_GPIO_PORT, &gpioinitstruct);

  /* Configure LCD_CS_PIN pin: LCD Card CS pin */
  gpioinitstruct.Pin   = LCD_CS_PIN;
  gpioinitstruct.Mode  = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Pull  = GPIO_NOPULL;
  gpioinitstruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SD_CS_GPIO_PORT, &gpioinitstruct);
  LCD_CS_HIGH();
  /*------------Put SD in SPI mode--------------*/
  /* SD SPI Config */
  SPIx_Init();

  /* SD chip select high */
  SD_CS_HIGH();

  /* Send dummy byte 0xFF, 10 times with CS high */
  /* Rise CS and MOSI for 80 clocks cycles */
  for (counter = 0; counter <= 9; counter++)
  {
    /* Send dummy byte 0xFF */
    SD_IO_WriteByte(SD_DUMMY_BYTE);
  }
}

/**
  * @brief  Set the SD_CS pin.
  * @param  pin value.
  */
void SD_IO_CSState(uint8_t val)
{
  if(val == 1)
  {
    SD_CS_HIGH();
}
  else
  {
    SD_CS_LOW();
  }
}

/**
  * @brief  Write byte(s) on the SD
  * @param  DataIn: Pointer to data buffer to write
  * @param  DataOut: Pointer to data buffer for read data
  * @param  DataLength: number of bytes to write
  */
void SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength)
  {
  /* Send the byte */
  SPIx_WriteReadData(DataIn, DataOut, DataLength);
}

/**
  * @brief  Write a byte on the SD.
  * @param  Data: byte to send.
  * @retval Data written
  */
uint8_t SD_IO_WriteByte(uint8_t Data)
{
  uint8_t tmp;

  /* Send the byte */
  SPIx_WriteReadData(&Data,&tmp,1);
  return tmp;
}

/**
  * @brief  Write an amount of data on the SD.
  * @param  Data: byte to send.
  * @param  DataLength: number of bytes to write
  */
void SD_IO_ReadData(uint8_t *DataOut, uint16_t DataLength)
{
  /* Send the byte */
  SD_IO_WriteReadData(DataOut, DataOut, DataLength);
  }

/**
  * @brief  Write an amount of data on the SD.
  * @param  Data: byte to send.
  * @param  DataLength: number of bytes to write
  */
void SD_IO_WriteData(const uint8_t *Data, uint16_t DataLength)
{
  /* Send the byte */
  SPIx_WriteData((uint8_t *)Data, DataLength);
}

/********************************* LINK LCD ***********************************/
/**
  * @brief  Initialize the LCD
  */
void LCD_IO_Init(void)
{
  GPIO_InitTypeDef  gpioinitstruct;

  /* LCD_CS_GPIO and LCD_DC_GPIO Periph clock enable */
  LCD_CS_GPIO_CLK_ENABLE();
  LCD_DC_GPIO_CLK_ENABLE();

  /* Configure LCD_CS_PIN pin: LCD Card CS pin */
  gpioinitstruct.Pin    = LCD_CS_PIN;
  gpioinitstruct.Mode   = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Speed  = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SD_CS_GPIO_PORT, &gpioinitstruct);

  /* Configure LCD_DC_PIN pin: LCD Card DC pin */
  gpioinitstruct.Pin    = LCD_DC_PIN;
  HAL_GPIO_Init(LCD_DC_GPIO_PORT, &gpioinitstruct);

  /* LCD chip select high */
  LCD_CS_HIGH();

  /* LCD SPI Config */
  SPIx_Init();
}

/**
  * @brief  Write command to select the LCD register.
  * @param  LCDReg: Address of the selected register.
  * @retval None
  */
void LCD_IO_WriteReg(uint8_t LCDReg)
{
  /* Reset LCD control line CS */
  LCD_CS_LOW();

  /* Set LCD data/command line DC to Low */
  LCD_DC_LOW();

  /* Send Command */
  SPIx_Write(LCDReg);

  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}

/**
* @brief  Write register value.
* @param  pData Pointer on the register value
* @param  Size Size of byte to transmit to the register
*/
void LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size)
{
  uint32_t counter = 0;

  /* Reset LCD control line CS */
  LCD_CS_LOW();

  /* Set LCD data/command line DC to High */
  LCD_DC_HIGH();

  if (Size == 1)
  {
    /* Only 1 byte to be sent to LCD - general interface can be used */
    /* Send Data */
    SPIx_Write(*pData);
  }
  else
{
    /* Several data should be sent in a raw */
    /* Direct SPI accesses for optimization */
    for (counter = Size; counter != 0; counter--)
  {
      while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
  {
}
      /* Need to invert bytes for LCD*/
      *((__IO uint8_t*)&hnucleo_Spi.Instance->DR) = *(pData+1);

      while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
{
}
      *((__IO uint8_t*)&hnucleo_Spi.Instance->DR) = *pData;
      counter--;
      pData += 2;
  }

    /* Wait until the bus is ready before releasing Chip select */
    while(((hnucleo_Spi.Instance->SR) & SPI_FLAG_BSY) != RESET)
  {
  }
  }

  /* Deselect : Chip Select high */
  LCD_CS_HIGH();
}

/**
  * @brief  Wait for loop in ms.
  * @param  Delay in ms.
  * @retval None
  */
void LCD_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}

#endif /* HAL_SPI_MODULE_ENABLED */
