/**
*   @file    Flash.c
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
#include "Flash.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

STATIC uint8 s_savWDT;

STATIC halIntState_t fuIntState;

// Function prototypes
STATIC void initFlash(void);
STATIC void doneFlash(void);

STATIC void initFlash(void)
{
  HAL_ENTER_CRITICAL_SECTION( fuIntState );  // Hold off interrupts.

  s_savWDT = WDTCTL & 0xFF;

  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

#if defined FCTL2
  FCTL2 = FWKEY + FSSEL_1 + FN4 + FN3;  // Flash Timing Generator as MCLK/24 -> 333 kHz.
#endif

#if defined HAL_BOARD_F5438
  if (FCTL3 & LOCKA)
  {
    FCTL3 = FWKEY + LOCKA;  // Clear the user info pages lock for writing the IEEE.
  }
#endif
}

STATIC void doneFlash()
{
  // restore WDT
  WDTCTL = WDTPW + s_savWDT;

  HAL_EXIT_CRITICAL_SECTION( fuIntState );   // Re-enable interrupts.

  return;
}

void flashErasePage(uint8 *addr)
{
  initFlash();

  FCTL1 = FWKEY + ERASE;               // Set Erase bit
  FCTL3 = FWKEY;                       // Clear Lock bit
  *addr = 0;                           // Dummy write to erase Flash segment
  FCTL1 = FWKEY;                       // Clear ERASE bit
  FCTL3 = FWKEY + LOCK;                // Set LOCK bit

  doneFlash();
  return;
}

void flashWrite( uint8 *addr, uint16 len, uint8 *buf )
{
  initFlash();

  FCTL3 = FWKEY;                // Clear Lock bit
  FCTL1 = FWKEY + WRT;          // Set WRT bit for write operation

  while ( len-- )
  {
    *addr++ = *buf++;            // Write value to flash
  }

  FCTL1 = FWKEY;                // Clear WRT bit
  FCTL3 = FWKEY + LOCK;         // Set LOCK bit

  doneFlash();
}

#ifdef __cplusplus
}
#endif
/* End of file */
