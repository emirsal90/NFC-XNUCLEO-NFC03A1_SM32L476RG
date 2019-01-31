/**
  ******************************************************************************
  * @file    lib_nfctype5pcd.h
  * @author  MMY Application Team
  * @version $Revision: 1333 $
  * @date    $Date: 2015-11-05 10:49:42 +0100 (Thu, 05 Nov 2015) $
  * @brief   Generates the NFC type5 commands
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _LIB_NFCTYPE5PCD_H
#define _LIB_NFCTYPE5PCD_H

#include "lib_PCD.h"
#include "lib_iso15693pcd.h"

/* Error codes */
#define PCDNFCT5_OK 											PCDNFC_OK
#define PCDNFCT5_ERROR 										PCDNFC_ERROR
#define PCDNFCT5_ERROR_MEMORY_TAG					PCDNFC_ERROR_MEMORY_TAG
#define PCDNFCT5_ERROR_MEMORY_INTERNAL		PCDNFC_ERROR_MEMORY_INTERNAL
#define PCDNFCT5_ERROR_LOCKED 						PCDNFC_ERROR_LOCKED
#define PCDNFCT5_ERROR_NOT_FORMATED				PCDNFC_ERROR_NOT_FORMATED

/* Extended commands defined by the NFC Forum Type5 */
#define PCDNFCT5_CMDCODE_EXTREADSINGLEBLOCK		0x30
#define PCDNFCT5_CMDCODE_EXTWRITESINGLEBLOCK	0x31
#define PCDNFCT5_CMDCODE_EXTENDEDLOCKBLOCK    0x32
#define PCDNFCT5_CMDCODE_EXTREADMULBLOCKS			0x33
#define PCDNFCT5_CMDCODE_EXTENDEDGETSYSINFO		0x3B


/* Functions */
uint8_t PCDNFCT5_ReadNDEF( void );
uint8_t PCDNFCT5_WriteNDEF( void );

/* Extended commands defined by the NFC Forum Type5 */
int8_t PCDNFCT5_ExtendedReadSingleBlock (const uint8_t Flags, const uint8_t *UIDin, const uint16_t BlockNumber,uint8_t *pResponse );
int8_t PCDNFCT5_ExtendedGetSystemInfo ( const uint8_t Flags, const uint8_t ParamRequest, const uint8_t *UIDin, uint8_t *pResponse);
int8_t PCDNFCT5_ExtendedReadMultipleBlock (const uint8_t Flags, const uint8_t *UIDin, uint16_t BlockNumber, const uint8_t NbBlock, uint8_t *pResponse );
int8_t PCDNFCT5_ExtendedWriteSingleBlock(const uint8_t Flags, const uint8_t *UIDin, const uint16_t BlockNumber,const uint8_t *DataToWrite,uint8_t *pResponse );
int8_t PCDNFCT5_ExtendedLockSingleBlock ( const uint8_t Flags, const uint8_t *UIDin, const uint16_t BlockNumber,uint8_t *pResponse);

#endif /* _LIB_NFCTYPE5PCD_H */

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
