

// 1. Pre-processor Directives Section

#include "tm4c123gh6pm.h"
#include "led.h"
#include "PB.h"
// 2. Declarations Section
//   Global Variables
unsigned long In;  // input from PF4
unsigned long Out; // outputs to PF3,PF2,PF1 (multicolor LED)

//   Function Prototypes

void Delay(void);
void EnableInterrupts(void);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){ 
	LED_Init();
  PB_Init();
  
  while(1){
		In = GPIO_PORTF_DATA_R&0x10; // read PF4 into In
    if(In == 0x00){              // zero means SW1 is pressed
      GPIO_PORTF_DATA_R = 0x08;  // LED is green
		} else{                      // 0x10 means SW1 is not pressed
      GPIO_PORTF_DATA_R = 0x02;  // LED is red
    }
		
    Delay();                     // wait 0.1 sec
    GPIO_PORTF_DATA_R = 0x04;    // LED is blue
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
