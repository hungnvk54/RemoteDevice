/**
*   @file    Board.h
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
*   SW Version           : 1.0.1
*   Build Version        : 
*
*   (c) Copyright 2015 
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
Revision History:
                             Modification     Tracking
Author                       Date D/M/Y       Number     Description of Changes
Nguyen Van Hung              17/04/2015                 Initial code
==================================================================================================*/
#ifndef BOARD_H
#define BOARD_H

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
#include "macroUtility.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define DATA_INPUT_0_BIT        0U
#define DATA_INPUT_0_BV         BV(DATA_INPUT_0_BIT)
#define DATA_INPUT_0_DIR        P1DIR        
#define DATA_INPUT_0_DIN        P1IN
#define DATA_INPUT_0_REN        P1REN
#define DATA_INPUT_0_DOUT        P1OUT

#define DATA_INPUT_1_BIT        1U
#define DATA_INPUT_1_BV         BV(DATA_INPUT_1_BIT)
#define DATA_INPUT_1_DIR        P1DIR        
#define DATA_INPUT_1_DIN        P1IN
#define DATA_INPUT_1_REN        P1REN
#define DATA_INPUT_1_DOUT        P1OUT

#define DATA_INPUT_2_BIT        2U
#define DATA_INPUT_2_BV         BV(DATA_INPUT_2_BIT)
#define DATA_INPUT_2_DIR        P1DIR        
#define DATA_INPUT_2_DIN        P1IN
#define DATA_INPUT_2_REN        P1REN
#define DATA_INPUT_2_DOUT        P1OUT

#define DATA_INPUT_3_BIT        3U
#define DATA_INPUT_3_BV         BV(DATA_INPUT_3_BIT)
#define DATA_INPUT_3_DIR        P1DIR        
#define DATA_INPUT_3_DIN        P1IN
#define DATA_INPUT_3_REN        P1REN
#define DATA_INPUT_3_DOUT        P1OUT

#define DATA_VALID_BIT          4U
#define DATA_VALID_BV           BV(DATA_VALID_BIT)
#define DATA_VALID_DIR          P1DIR
#define DATA_VALID_DIN          P1IN
#define DATA_VALID_DOUT         P1OUT
#define DATA_VALID_REN          P1REN
#define DATA_VALID_IE           P1IE
#define DATA_VALID_IES          P1IES
#define DATA_VALID_IFG          P1IFG

#define DATA_INPUT_0_ALT_BIT          5U
#define DATA_INPUT_0_ALT_BV           BV(DATA_INPUT_0_ALT_BIT)
#define DATA_INPUT_0_ALT_DIR          P1DIR
#define DATA_INPUT_0_ALT_DIN          P1IN
#define DATA_INPUT_0_ALT_DOUT         P1OUT
#define DATA_INPUT_0_ALT_REN          P1REN
#define DATA_INPUT_0_ALT_IE           P1IE
#define DATA_INPUT_0_ALT_IES          P1IES
#define DATA_INPUT_0_ALT_IFG          P1IFG

#define DATA_OUTPUT_0_BIT        0U
#define DATA_OUTPUT_0_BV         BV(DATA_OUTPUT_0_BIT)
#define DATA_OUTPUT_0_DIR        P2DIR        
#define DATA_OUTPUT_0_DOUT       P2OUT

#define DATA_OUTPUT_1_BIT        1U
#define DATA_OUTPUT_1_BV         BV(DATA_OUTPUT_1_BIT)
#define DATA_OUTPUT_1_DIR        P2DIR        
#define DATA_OUTPUT_1_DOUT       P2OUT

#define DATA_OUTPUT_2_BIT        2U
#define DATA_OUTPUT_2_BV         BV(DATA_OUTPUT_2_BIT)
#define DATA_OUTPUT_2_DIR        P2DIR        
#define DATA_OUTPUT_2_DOUT       P2OUT

#define DATA_OUTPUT_3_BIT        3U
#define DATA_OUTPUT_3_BV         BV(DATA_OUTPUT_3_BIT)
#define DATA_OUTPUT_3_DIR        P2DIR        
#define DATA_OUTPUT_3_DOUT       P2OUT

#define INDICATOR_LED_BV         BV(4)
#define INDICATOR_LED_DIR        P2DIR        
#define INDICATOR_LED_DOUT       P2OUT

/*=============================MACROS TO INTERACT WITH OUTPUT======================================*/
#define CLEAR_OUTPUT_0           (DATA_OUTPUT_0_DOUT&=(~DATA_OUTPUT_0_BV))
#define SET_OUTPUT_0             (DATA_OUTPUT_0_DOUT|=DATA_OUTPUT_0_BV)
#define TOGGLE_OUTPUT_0          (DATA_OUTPUT_0_DOUT^=DATA_OUTPUT_0_BV)

#define CLEAR_OUTPUT_1           (DATA_OUTPUT_1_DOUT&=(~DATA_OUTPUT_1_BV))
#define SET_OUTPUT_1             (DATA_OUTPUT_1_DOUT|=DATA_OUTPUT_1_BV)
#define TOGGLE_OUTPUT_1          (DATA_OUTPUT_1_DOUT^=DATA_OUTPUT_1_BV)

#define CLEAR_OUTPUT_2           (DATA_OUTPUT_2_DOUT&=(~DATA_OUTPUT_2_BV))
#define SET_OUTPUT_2             (DATA_OUTPUT_2_DOUT|=DATA_OUTPUT_2_BV)
#define TOGGLE_OUTPUT_2          (DATA_OUTPUT_2_DOUT^=DATA_OUTPUT_2_BV)

#define CLEAR_OUTPUT_3           (DATA_OUTPUT_3_DOUT&=(~DATA_OUTPUT_3_BV))
#define SET_OUTPUT_3             (DATA_OUTPUT_3_DOUT|=DATA_OUTPUT_3_BV)
#define TOGGLE_OUTPUT_3          (DATA_OUTPUT_3_DOUT^=DATA_OUTPUT_3_BV)

#define CLEAR_INDICATOR_LED      (INDICATOR_LED_DOUT=&(~INDICATOR_LED_BV))
#define SET_INDICATOR_LED        (INDICATOR_LED_DOUT=|INDICATOR_LED_BV)
#define TOGGLE_INDICATOR_LED     (INDICATOR_LED_DOUT=^INDICATOR_LED_BV)

#define INTERACT_ALL(dir,type,x)           st(  DATA_##dir##_0_##type ##x##= DATA_##dir##_0_BV; \
                                            DATA_##dir##_1_##type ##x##= DATA_##dir##_1_BV; \
                                            DATA_##dir##_2_##type ##x##= DATA_##dir##_2_BV; \
                                            DATA_##dir##_3_##type ##x##= DATA_##dir##_3_BV; \
                                     )


#define INTERACT_NOT_ALL(dir,type,x)           st(  DATA_##dir##_0_##type ##x##= (~DATA_##dir##_0_BV); \
                                                        DATA_##dir##_1_##type ##x##= (~DATA_##dir##_1_BV); \
                                                        DATA_##dir##_2_##type ##x##= (~DATA_##dir##_2_BV); \
                                                        DATA_##dir##_3_##type ##x##= (~DATA_##dir##_3_BV); \
                                                      )

#define SCAN_DATA(x)             st(x=(((DATA_INPUT_0_DIN&DATA_INPUT_0_BV)>>DATA_INPUT_0_BIT)<<0U); \
                                    x |= (((DATA_INPUT_1_DIN&DATA_INPUT_1_BV)>>DATA_INPUT_1_BIT)<<1U); \
                                    x |= (((DATA_INPUT_2_DIN&DATA_INPUT_2_BV)>>DATA_INPUT_2_BIT)<<2U); \
                                    x |= (((DATA_INPUT_3_DIN&DATA_INPUT_3_BV)>>DATA_INPUT_3_BIT)<<3U); \
                                    x &= 0x0F; \
                                    )
                                    
#define PUT_DATA(x)              st( DATA_OUTPUT_0_DOUT^=(((x>>0)&0x01U)<<DATA_OUTPUT_0_BIT); \
                                     DATA_OUTPUT_1_DOUT^=(((x>>1)&0x01U)<<DATA_OUTPUT_1_BIT); \
                                     DATA_OUTPUT_2_DOUT^=(((x>>2)&0x01U)<<DATA_OUTPUT_2_BIT); \
                                     DATA_OUTPUT_3_DOUT^=(((x>>3)&0x01U)<<DATA_OUTPUT_3_BIT); \
                                    )

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void Board_Init(void);
#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/* End of file */
