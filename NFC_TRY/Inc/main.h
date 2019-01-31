/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

#include "common.h"
#include "../Inc/DriversHeader/com.h"

#include "../Inc/lib_NDEFheader/lib_NDEF_URI.h"
#include "../Inc/lib_NDEFheader/lib_NDEF_SMS.h"
#include "../Inc/lib_NDEFheader/lib_NDEF_Text.h"
#include "../Inc/lib_NDEFheader/lib_NDEF_Email.h"
#include "../Inc/lib_NDEFheader/lib_NDEF_Geo.h"
#include "../Inc/commonHeader/lib_95HFConfigManager.h"


#include "stdint.h"
/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
#define BULK_MAX_PACKET_SIZE            0x00000040

/* Regarding board antenna (and matching) appropriate
value may be modified to optimized RF performances */
/* Analogue configuration register
 ARConfigB	bits  7:4	MOD_INDEX	Modulation index to modulator
                      3:0	RX_AMP_GAIN	Defines receiver amplifier gain
For type A you can also adjust the Timer Window
*/

/******************  PCD  ******************/
/* ISO14443A */
#define PCD_TYPEA_ARConfigA	        0x01
#define PCD_TYPEA_ARConfigB	        0xDF

#define PCD_TYPEA_TIMERW            0x5A

/* ISO14443B */
#define PCD_TYPEB_ARConfigA	        0x01
#define PCD_TYPEB_ARConfigB	        0x51

/* Felica */
#define PCD_TYPEF_ARConfigA	        0x01
#define PCD_TYPEF_ARConfigB	        0x51

/* ISO15693 */
#define PCD_TYPEV_ARConfigA	        0x01
#define PCD_TYPEV_ARConfigB	        0xD1

/******************  PICC  ******************/
/* ISO14443A */
#define PICC_TYPEA_ACConfigA            0x27  /* backscaterring */

/* ISO14443B */
#define PICC_TYPEB_ARConfigD            0x0E  /* card demodulation gain */
#define PICC_TYPEB_ACConfigA            0x17  /* backscaterring */

/* Felica */
#define PICC_TYPEF_ACConfigA            0x17  /* backscaterring */

/* Exported constants --------------------------------------------------------*/
#ifndef USE_CR95HF_UART
#define SPI_INTERRUPT_MODE_ACTIVATED
#endif

/**
 * @brief  TIMER definitions
 */

/* --------------------------------------------------------------------------
* Delay TIMER configuration (ms)
* -------------------------------------------------------------------------- */
//#define TIMER_DELAY					TIM2
//#define TIMER_DELAY_PERIOD			72
//#define TIMER_DELAY_PRESCALER		1000

/* --------------------------------------------------------------------------
* Delay TIMER configuration (탎)
* --------------------------------------------------------------------------- */
#define TIMER_US_DELAY					TIM2
#define TIMER_US_DELAY_PERIOD			35
#define TIMER_US_DELAY_PRESCALER		1

/*----------------------------------------------------------------------------*/


#define TIMER_TIMEOUT					TIM3
#define APPLI_TIMER_TIMEOUT				TIM4
#define TIMER_TIMEOUT_IRQ_CHANNEL		TIM3_IRQn
#define APPLI_TIMER_TIMEOUT_IRQ_CHANNEL	TIM4_IRQn
#define EXTI_RFTRANS_95HF_IRQ_CHANNEL	EXTI15_10_IRQn
#define TIMER_TIMEOUT_IRQ_HANDLER		TIM3_IRQHandler
#define APPLI_TIMER_TIMEOUT_IRQ_HANDLER	TIM4_IRQHandler
#define RFTRANS_95HF_IRQ_HANDLER		EXTI15_10_IRQHandler


/*----------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------
* timeout configuration (ms)
* --------------------------------------------------------------------------
* 72 MHz / 72 = 1MHz (1us )
* 1탎 * 1000 + 1탎 ~= 1ms
* -------------------------------------------------------------------------- */

#define TIMER_TIMEOUT_PERIOD		1000
#define TIMER_TIMEOUT_PRESCALER		72

/* --------------------------------------------------------------------------
* timeout configuration (ms)
* --------------------------------------------------------------------------
* 72 MHz / 72 = 1MHz (1us )
* 1탎 * 1000 + 1탎 ~= 1ms
* -------------------------------------------------------------------------- */

#define APPLI_TIMER_TIMEOUT_PERIOD	1000
#define APPLI_TIMER_TIMEOUT_PRESCALER	72

/**
 * @brief  NVIC definitions
 */

/**
 *	@brief  Interrupts configuration
|---------------|-----------------------|-------------------|-------------------|
|	 name		|preemption priority	|sub proiority	    |	channel	        |
|---------------|-----------------------|-------------------|-------------------|
| 95HF			|	0		|	0           |	EXTI15_10_IRQn	|
|---------------|-----------------------|-------------------|-------------------|
| delay			|	0		|	0           |	TIM2_IRQn	|
|---------------|-----------------------|-------------------|-------------------|
| timeout		|	0		|	0           |	TIM3_IRQn	|
|---------------|-----------------------|-------------------|-------------------|
| appli timeout	|	0		|	0           |	TIM4_IRQn	|
|---------------|-----------------------|-------------------|-------------------|
 */
#define EXTI_RFTRANS_95HF_PREEMPTION_PRIORITY   1
#define EXTI_RFTRANS_95HF_SUB_PRIORITY		1

#define TIMER_DELAY_PREEMPTION_PRIORITY		1
#define TIMER_DELAY_SUB_PRIORITY		3
#define TIMER_DELAY_IRQ_CHANNEL			TIM2_IRQn
#define TIMER_DELAY_PREEMPTION_HIGHPRIORITY	0
#define TIMER_DELAY_SUB_HIGHPRIORITY		0

#define TIMER_TIMEOUT_PREEMPTION_PRIORITY	0
#define TIMER_TIMEOUT_SUB_PRIORITY		0

#define APPLI_TIMER_TIMEOUT_PREEMPTION_PRIORITY	0
#define APPLI_TIMER_TIMEOUT_SUB_PRIORITY	1

/**
 * @brief  IRQ handler functions names
 */
#define TIMER_DELAY_IRQ_HANDLER			TIM2_IRQHandler


/* Exported functions ------------------------------------------------------- */
void drvInt_Enable_Reply_IRQ(void);
void drvInt_Enable_RFEvent_IRQ(void);
void drvInt_Disable_95HF_IRQ(void);

/* Exported functions ------------------------------------------------------- */
void HAL_Delay_Us(uint16_t delay);

/* Timeout use during the communication with the 95HF device with SPI or UART path */
void StartTimeOut(uint16_t delay);
void StopTimeOut(void);
void StartAppliTimeOut(uint16_t delay);
void StopAppliTimeOut(void);

void Timer_Structure_Config(void);
void FillTagURI(char* pTagType);
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
