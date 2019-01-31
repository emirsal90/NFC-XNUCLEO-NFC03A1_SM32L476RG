/**
  ******************************************************************************
  * @file    drv_led.h
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

/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __DRV_LED_H
#define __DRV_LED_H



/* Includes ----------------------------------------------------------------------------- */
#include "main.h"
#include "stdint.h"
#include "stm32l476xx.h"
#include "stm32l4xx_hal.h"

/** @addtogroup BSP
  * @{
  */

/** @defgroup X_NUCLEO_NFC03A1_Led
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup X_NUCLEO_NFC03A1_Led_Exported_Types
  * @{
  */
  /**
 * @brief  NFC03A1 Led enumerator definition
 */
typedef enum
{
  GREEN_LED1 = 0,
  BLUE_LED2,
  GREEN_LED3,
  BLUE_LED4,
} NFC03A1_Led_E;

/**
 * @brief  NFC03A1 Led structure definition
 */
typedef struct
{
  uint16_t          NFC03A1_LED_PIN;
  GPIO_TypeDef *    NFC03A1_LED_PIN_PORT;
} NFC03A1_Led_TypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup X_NUCLEO_NFC03A1_Led_Exported_Constants
  * @{
  */
#define NFC03A1_LED1_PIN               GPIO_PIN_8
#define NFC03A1_LED1_PIN_PORT          GPIOA
#define NFC03A1_LED2_PIN               GPIO_PIN_10
#define NFC03A1_LED2_PIN_PORT          GPIOB
#define NFC03A1_LED3_PIN               GPIO_PIN_4
#define NFC03A1_LED3_PIN_PORT          GPIOB
#define NFC03A1_LED4_PIN               GPIO_PIN_5
#define NFC03A1_LED4_PIN_PORT          GPIOB
/**
  * @}
  */

/* External variables --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup X_NUCLEO_NFC03A1_Led_Exported_Macro
  * @{
  */
#define NFC03A1_LED_GPIO_CLK_ENABLE()  do {                      \
                                            __GPIOA_CLK_ENABLE();\
                                            __GPIOB_CLK_ENABLE();\
                                          } while(0)
/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @defgroup X_NUCLEO_NFC03A1_Led_Exported_Functions
  * @{
  */
void initLED(void);
void LED_On(const NFC03A1_Led_E led);
void LED_Off(const NFC03A1_Led_E led);
void LED_Toggle(const NFC03A1_Led_E led);
void LED_AllOff(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif /* __DRV_LED_H */

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
