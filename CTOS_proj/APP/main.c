

// 1. Pre-processor Directives Section

#include "tm4c123gh6pm.h"
#include "led.h"
#include "PB.h"
#include "port.h"
// 2. Declarations Section
//   Global Variables
PB_STATE In;  // input from PF4
unsigned long Out; // outputs to PF3,PF2,PF1 (multicolor LED)

//   Function Prototypes

void Delay(void);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){


  PORT_init();
  LED_Init();
  
  
  while(1){

		In = PB_GetButtonState(PB_ONE_ID); // read PF4 into In
    if(In == BUTTON_PRESSED){              // zero means SW1 is pressed
      LED_On(GREEN_LED_ID);     // LED is green
		} else{                      // 0x10 means SW1 is not pressed
      LED_On(RED_LED_ID);  // LED is red
    }
		
    Delay();                     // wait 0.1 sec
    LED_On(BLUE_LED_ID);    // LED is blue
    Delay();                     // wait 0.1 sec

  }
}



// Subroutine to wait 0.1 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){unsigned long volatile time;
  time = 727240*200/91;  // 0.1sec
  while(time){
		time--;
  }
}

