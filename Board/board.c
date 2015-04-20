/**
*   @file    Board.c
*   @version 1.0.0
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
*   SW Version           : 1.0.0
*   Build Version        : 
*
*   (c) Copyright 17/04/2015
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
*                                               REVISION HISTORY
                             Modification     Tracking
Author                       Date D/M/Y       Number     Description of Changes
Nguyen Van Hung              17/04/2015                 Initial code
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
#include "Board.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint8 state=0;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void Board_Init(void)
{
  //config Data Input
  INTERACT_NOT_ALL(INPUT,DIR,&);
  
  DATA_VALID_DIR &= (~DATA_VALID_BIT);
  
  INTERACT_ALL( OUTPUT, DIR, | );
  
  INDICATOR_LED_DIR |= INDICATOR_LED_BV;
  
  /*Enable pull-down register*/
  INTERACT_ALL( INPUT, REN, | );
  
  DATA_VALID_REN |= DATA_VALID_BV;
  DATA_INPUT_0_ALT_REN |= DATA_INPUT_0_ALT_BV;
  
  /*config pull-down register*/
  INTERACT_NOT_ALL( INPUT, DOUT, & );
  
  DATA_VALID_DOUT &= ( ~DATA_VALID_BV );
  
  DATA_INPUT_0_ALT_DOUT &= ( ~DATA_INPUT_0_ALT_BV );
  
  INTERACT_NOT_ALL( OUTPUT, DOUT, & );
  
  INDICATOR_LED_DOUT |= INDICATOR_LED_BV;
  
  /* Select edge */
  DATA_VALID_IES &= ( ~DATA_VALID_BV ); /* low-to-high edge select */
  DATA_INPUT_0_ALT_IES &= (~DATA_INPUT_0_ALT_BV);
  /* Clear all interrupt flag */
  DATA_VALID_IFG &= ( ~DATA_VALID_BV );
  DATA_INPUT_0_ALT_IFG &= (~DATA_INPUT_0_ALT_BV);
  
  /*config Interupt mask*/
  DATA_VALID_IE |= DATA_VALID_BV; /* Enable interrupt */
  DATA_INPUT_0_ALT_IE |= DATA_INPUT_0_ALT_BV; /* Enable interrupt */
  
}

HAL_ISR_FUNCTION(P1_ISR, PORT1_VECTOR)
{
      if( DATA_VALID_BV & P1IFG )
      {
        do
        {
        SCAN_DATA( state );
      
        PUT_DATA( state );
        }while( 0 == state );
        /* clear flag */
        DATA_VALID_IFG &= (~DATA_VALID_BV);
      }
      
      if ( DATA_INPUT_0_ALT_BV & P1IFG )
      {
        TOGGLE_OUTPUT_0;
        DATA_INPUT_0_ALT_IFG &= (~DATA_INPUT_0_ALT_BV);
      }
}

#ifdef __cplusplus
}
#endif
/* End of file */
