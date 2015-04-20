#ifndef FLASH_H
#define FLASH_H
/**
*   @file    Flash.h
*   @version Major.minor.path
*
*   @brief   
*   @details 
*
*/
/*==================================================================================================
*   Project              : 
*   Platform             : 
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : ..
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : ..
*   Build Version        : 
*
*   (c) Copyright Y/mm/dd 
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
*                                               REVISION HISTORY
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "type.h"
#include "compiler.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define FLASH_INFO_SEGMENT_SIZE         (0x64U)
#define FLASH_SEGMENT_START_ADRR        (0x01000U)
  
#define FLASH_UINT8_SEGMENT_D        ((uint8 *)(FLASH_SEGMENT_START_ADRR + 0*FLASH_INFO_SEGMENT_SIZE))
#define FLASH_UINT16_SEGMENT_D       ((uint16 *)(FLASH_SEGMENT_START_ADRR + 0*FLASH_INFO_SEGMENT_SIZE)) 

#define FLASH_UINT8_SEGMENT_C        ((uint8 *)(FLASH_SEGMENT_START_ADRR + 1*FLASH_INFO_SEGMENT_SIZE))
#define FLASH_UINT16_SEGMENT_C       ((uint16 *)(FLASH_SEGMENT_START_ADRR + 1*FLASH_INFO_SEGMENT_SIZE))

#define FLASH_UINT8_SEGMENT_B        ((uint8 *)(FLASH_SEGMENT_START_ADRR + 2*FLASH_INFO_SEGMENT_SIZE))
#define FLASH_UINT16_SEGMENT_B       ((uint16 *)(FLASH_SEGMENT_START_ADRR + 2*FLASH_INFO_SEGMENT_SIZE))

#define FLASH_UINT8_SEGMENT_A        ((uint8 *)(FLASH_SEGMENT_START_ADRR + 3*FLASH_INFO_SEGMENT_SIZE))
#define FLASH_UINT16_SEGMENT_A       ((uint16 *)(FLASH_SEGMENT_START_ADRR + 3*FLASH_INFO_SEGMENT_SIZE))

/*********************************************************************
 * FUNCTIONS
 */
void flashErasePage( uint8 *addr );

void flashWrite( uint8 *addr, uint16 len, uint8 *buf );

#ifdef __cplusplus
}
#endif

#endif /* End of #ifndef FLASH_H */
/* End of file */
