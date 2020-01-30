/*!**********************************************************************************************************************
@file main.c                                                                
@brief Main system file for the EiE firmware.  
***********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32SystemTime1ms = 0;
volatile u32 G_u32SystemTime1s = 0;
volatile u32 G_u32SystemFlags = 0;

/*--------------------------------------------------------------------------------------------------------------------*/
/* External global variables defined in other files (must indicate which file they are defined in) */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "Main_" and be declared as static.
***********************************************************************************************************************/


/*!**********************************************************************************************************************
@fn void main(void)
@brief Main program where all tasks are initialized and executed.


***********************************************************************************************************************/

void main(void)
{
  bool bLedOn = FALSE;
  u32 u32LoopCounter = 0;
  
  /* Low level initialization */
  WatchDogSetup();
  ClockSetup();
  GpioSetup();
  
  /* Super loop*/
  while(1)
  {
    WATCHDOG_BONE();
    
    HEARTBEAT_OFF();
    do
    {
      SystemSleep();
    } while (G_u32SystemFlags & _SYSTEM_SLEEPING);
    HEARTBEAT_ON();
      
  } /* end while(1) main super loop */
  
} /* end main() */




/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File */
/*--------------------------------------------------------------------------------------------------------------------*/
