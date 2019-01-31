/**
  ******************************************************************************
  * @file    drv_led.c
  * @author  MMY Application Team
  * @version $Revision: 1508 $
  * @date    $Date: 2016-01-08 09:50:04 +0100 (Fri, 08 Jan 2016) $
  * @brief   This file provides set of firmware functions to manage Leds
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under ST MYLIBERTY SOFTWARE LICENSE AGREEMENT (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/myliberty
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,
  * AND SPECIFICALLY DISCLAIMING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "../Inc/DriversHeader/drv_led.h"

/** @addtogroup BSP
 * @{
 */

/** @addtogroup X_NUCLEO_NFC03A1_Led
 * @{
 */
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
/** @defgroup X_NUCLEO_NFC03A1_Led_Global_Variables
 * @{
 */
NFC03A1_Led_TypeDef NFC03A1_Led[4] = { { NFC03A1_LED1_PIN, NFC03A1_LED1_PIN_PORT } ,
                                       { NFC03A1_LED2_PIN, NFC03A1_LED2_PIN_PORT } ,
                                       { NFC03A1_LED3_PIN, NFC03A1_LED3_PIN_PORT } ,
                                       { NFC03A1_LED4_PIN, NFC03A1_LED4_PIN_PORT } };
/**
 * @}
 */

/* Public Functions ----------------------------------------------------------*/
/** @defgroup X_NUCLEO_NFC03A1_Led_Public_Functions
 * @{
 */

/**
  * @brief  This function initialize the GPIO to manage the Leds through GPIO
  * @param  None
  * @retval None
  */
void initLED(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  NFC03A1_LED_GPIO_CLK_ENABLE();

  /* Configure GPIO for LEDs (PA8,PB10,PB4,PB5)*/
  GPIO_InitStruct.Pin 	= NFC03A1_LED2_PIN | NFC03A1_LED3_PIN | NFC03A1_LED4_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_LOW;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  HAL_GPIO_Init(NFC03A1_LED2_PIN_PORT, &GPIO_InitStruct);

#ifdef STM32F103xB
  __HAL_AFIO_REMAP_SWJ_NONJTRST();
#endif

  GPIO_InitStruct.Pin = NFC03A1_LED1_PIN;
  HAL_GPIO_Init(NFC03A1_LED1_PIN_PORT, &GPIO_InitStruct);

  LED_Off(GREEN_LED3);
  LED_Off(BLUE_LED2);
  LED_Off(BLUE_LED4);
  LED_Off(GREEN_LED1);

}

/**
  * @brief  This function light on selected Led
  * @param  led : Led to be lit on
  * @retval None
  */
void LED_On(const NFC03A1_Led_E led)
{
  HAL_GPIO_WritePin( NFC03A1_Led[led].NFC03A1_LED_PIN_PORT, NFC03A1_Led[led].NFC03A1_LED_PIN, GPIO_PIN_SET );
}

/**
  * @brief  This function light off selected Led
  * @param  led : Led to be lit off
  * @retval None
  */
void LED_Off(const NFC03A1_Led_E led)
{
  HAL_GPIO_WritePin( NFC03A1_Led[led].NFC03A1_LED_PIN_PORT, NFC03A1_Led[led].NFC03A1_LED_PIN, GPIO_PIN_RESET );
}

/**
  * @brief  Toggles the selected LED
  * @param  led : Specifies the Led to be toggled
  * @retval None
  */
void LED_Toggle(const NFC03A1_Led_E led)
{
  HAL_GPIO_TogglePin( NFC03A1_Led[led].NFC03A1_LED_PIN_PORT, NFC03A1_Led[led].NFC03A1_LED_PIN );
}

/**
  * @brief  this function turns all LEDs Off.
  */
void LED_AllOff(void)
{
  LED_Off(GREEN_LED1);
  LED_Off(BLUE_LED2);
  LED_Off(GREEN_LED3);
  LED_Off(BLUE_LED4);
}

/**
 * @}
 */

 /**
 * @}
 */

 /**
 * @}
 */

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
