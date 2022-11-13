
// 1. Pre-processor Directives Section

#include "tm4c123gh6pm.h"
#include "led.h"
#include "PB.h"
#include "port.h"
#include "NVIC.h"
// 2. Declarations Section
//   Global Variables


unsigned long Out; // outputs to PF3,PF2,PF1 (multicolor LED)

//   Function Prototypes

void Delay(void);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void)
{

  PB_STATE ButtonOne_state;
  PB_STATE ButtonTwo_state;  
  uint8 ON_time_sec = 5;
  uint8 OFF_time_sec = 5;
  PORT_init();
  LED_Init();
  NVIC_EnableInterrupt(30);
  NVIC_EnableInterrupt(40);

  while(1)
  {

/*
    ButtonOne_state = PB_GetButtonState(PB_ONE_ID); // read PF4 into In
    ButtonTwo_state = PB_GetButtonState(PB_TWO_ID);
    if(ButtonOne_state == BUTTON_PRESSED ||ButtonTwo_state == BUTTON_PRESSED )
    {              // zero means SW1 is pressed
      LED_On(GREEN_LED_ID);     // LED is green
    } else{                      // 0x10 means SW1 is not pressed
      LED_On(RED_LED_ID);  // LED is red
    }
    
    Delay();                     // wait 0.1 sec
    LED_On(BLUE_LED_ID);    // LED is blue
    Delay();                     // wait 0.1 sec
*/
  }
  
}



// Subroutine to wait 0.1 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){unsigned long volatile time;
  time = 727240*200/91*5;  // 0.1sec
  while(time){
		time--;
  }
}

void GPIOF_Handler(void )
{

  if ( GPIO_PORTF_MIS_R & 0x10)
    {
      LED_On(GREEN_LED_ID);     // LED is green

    }
  else if ( GPIO_PORTF_MIS_R & 0x01)
  {
      LED_On(RED_LED_ID);     // LED is green
  }
}

