
#include "msp430g2553.h"
#include "Flash.h"
#include "Board.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  Board_Init();

    __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt

  while(1);
}
