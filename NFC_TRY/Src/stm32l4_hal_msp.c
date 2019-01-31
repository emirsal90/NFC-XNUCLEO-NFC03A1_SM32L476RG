/**
  ******************************************************************************
  * @file    stm32l4_hal_msp.c
  * @author  MMY Application Team
  * @version $Revision: 1506 $
  * @date    $Date: 2016-01-08 09:48:13 +0100 (Fri, 08 Jan 2016) $
  * @brief   This file provides code for the MSP Initialization
  *          and de-Initialization.
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
#include "main.h"

/** @addtogroup X_NUCLEO_NFC03A1_Applications
  * @{
  */

/** @defgroup CR95HF_TagDetect_Application
  * @brief HAL MSP module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
extern TIM_HandleTypeDef	TimHandleDelay;
extern TIM_HandleTypeDef	TimHandleTimeout;
extern TIM_HandleTypeDef        TimHandleAppli;

extern volatile bool uDelayUs;
extern volatile bool uTimeOut;
extern volatile bool uAppliTimeOut;

extern uint16_t delay_us;
extern uint16_t delay_appli;
extern uint16_t delay_timeout;
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief  Initializes the Global MSP.
  * @param  None
  * @retval None
  */

#if 0
void HAL_MspInit(void)
{
  /* Sets the priority grouping field */
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

}
#endif


/**
  * @brief TIM MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  * @param htim: TIM handle pointer
  * @retval None
  */
#if 0
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM2)
  {
    /* Peripheral clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();
    /* Set the TIM2 priority */
    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 1);
    /* Enable the TIMx global Interrupt */
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  }
  else if(htim->Instance==TIM3)
  {
    /* Peripheral clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();
    /* Set the TIM3 priority */
    HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);
    /* Enable the TIMx global Interrupt */
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  }
  else if(htim->Instance==TIM4)
  {
    /* Peripheral clock enable */
    __HAL_RCC_TIM4_CLK_ENABLE();
    /* Set the TIM3 priority */
    HAL_NVIC_SetPriority(TIM4_IRQn, 0, 1);
    /* Enable the TIMx global Interrupt */
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
  }


}
#endif

/**
 *	@brief  This function starts timer delay
 *  @param  delay : delay in microseconds (1us).
 *  @retval None
 */

void HAL_Delay_Us(uint16_t delay)
{
  /* Set the TimeOut flag to false */
  uDelayUs = false;
  delay_us = delay;

  /* Enable the us delay timer */
  __HAL_TIM_SET_COUNTER(&TimHandleDelay, delay);
  HAL_TIM_Base_Start_IT(&TimHandleDelay);

  while(uDelayUs != true);
}

/**
 *	@brief  This function starts the time out used to avoid the STM32 freeze
 *  @param  delay : delay in tenth of milliseconds (100us).
 *  @retval None
 */
#if 0
void StartTimeOut(uint16_t delay)
{
  /* Set the TimeOut flag to false */
  uTimeOut = false;
  delay_timeout = delay;

  /* Enable the Time out timer */
  __HAL_TIM_SET_COUNTER(&TimHandleTimeout, delay);
  HAL_TIM_Base_Start_IT(&TimHandleTimeout);
}

/**
 *	@brief  Stop the timer used for the time out
 *  @param  None
 *  @retval None
 */
void StopTimeOut(void)
{
  /* Disable the Time out timer */
  HAL_TIM_Base_Stop_IT(&TimHandleTimeout);
}
#endif


/**
 *	@brief  This function starts the time out used to avoid the STM32 freeze
 *  @param  delay : delay in tenth of milliseconds (100us).
 *  @retval None
 */
void StartAppliTimeOut(uint16_t delay)
{
  /* Set the AppliTimeOut flag to false */
  uAppliTimeOut = false;
  delay_appli = delay;

  /* Enable the Application timer */
  __HAL_TIM_SET_COUNTER(&TimHandleAppli, delay);
  HAL_TIM_Base_Start_IT(&TimHandleAppli);
}

/**
 *	@brief  Stop the timer used for the time out
 *  @param  None
 *  @retval None
 */
void StopAppliTimeOut(void)
{
  /* Disable the Time out timer */
  HAL_TIM_Base_Stop_IT(&TimHandleAppli);
}

/**
 *	@brief  this function generate a random value
 */
uint16_t random(uint16_t min, uint16_t max)
{
  return (((SysTick->VAL)%(max - min + 1)) + min);
}

/* USER CODE END 1 */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
