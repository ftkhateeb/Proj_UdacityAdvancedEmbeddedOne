/*
Lesson_15.2_Blink_PF1_using_Periodic_Mode_&_SW_Interrupt 

This program demonstrates the use of TimerA of Timer0 block to use timeout 
events to trigger interrupts. Timer1A is configured to timeout once every second. 
In the interrupt handler, the red LED is toggled. 

Also, the setup to trigger an interrupt using SW0 and SW1 with higher priority 
that TIMER0A. 

Notice in Table 2-9 from Datasheet (p.104): 
IRQ19 is assigned to Timer1A of Timer0 block. 

All LEDs are high active (a "1" turns ON the LED).
PF1 - red LED 0x02
PF2 - blue LED 0x04
PF3 -green LED 0x08

*/

#include <stdint.h>
#include <TM4C123GH6PM.h>       //Tiva C Series TM4C123G “Header File”.

void GPIO_init(void);
void timer0A_init(void);
void NVIC_init(void);

int main(void)
{
  GPIO_init();
  timer0A_init();
  NVIC_init();
 
  __enable_irq();               // Global enable IRQs
  
  while (1)
  {
  }
}

void GPIO_init(void)
{
  /* ---------------------------- PART I ---------------------------- */
  /* ------------ GPIOF Initialization and Configuration ------------ */
  SYSCTL->RCGCGPIO |= 0x20;     /* STEP1. Enable clock signal to the GPIOF */     
  GPIOF->DIR = 0x0E;            /* STEP2. Set PORTF3-1 output for LEDs. */
  /*SKIP STEP3-4*/
  GPIOF->LOCK = 0x4C4F434B;     /* STEP5A. unlock the GPIOCR Commit register. */
  GPIOF->CR = 0x01;             /* STEP5B. make PORTF0 configurable. */
  GPIOF->LOCK = 0;
  GPIOF->PUR = 0x11;            /* STEP5C.enable pull up for PORTF4, 0. */
  GPIOF->DEN = 0x1F;            /* STEP6. Enable PORTF4-0 DIGITAL pins */           
  GPIOF->IS  &= ~0x11;          /* STEP7A. make bit 4, 0 edge sensitive */
  GPIOF->IBE &= ~0x11;          /* STEP7B. trigger is controlled by IEV */
  GPIOF->IEV &= ~0x11;          /* STEP7C. falling edge trigger */
  GPIOF->ICR |= 0x11;           /* clear any prior interrupt */
  GPIOF->IM  |= 0x11;           /* STEP7D. unmaks interrupt (PF4 and PF0 are enable)*/
  /* ------------------------ PART I (END) -------------------------- */  
}

void timer0A_init(void)
{
  /* --------------------------- PART II -------------------------- */
  /* ----------- GPTM Initialization and Configuration ---------- */
  SYSCTL->RCGCTIMER |= 1;       /* STEP1. Enable clock signal to timer module 0. */  
  TIMER0->CFG = 0X04;           /* STEP2. Configure GPTM global operation as a 16-bit mode */ 
  TIMER0->CTL = 0;              /* STEP3. Disable Timer before initialization */
  TIMER0->TAMR = 0x02;          /* STEP4. Configure TimerA0 as Periodic Mode & down-counter */
  TIMER0->TAPR =250;            /* STEP5. Enable the 8-bit Prescaler register for TimerA */
  TIMER0->TAILR = 64000;        /* STEP6. Load the start value into the(GPTMTnILR) Register */
  TIMER0->IMR |= 0x01;          /* STEP7. Enable GPTM controller-level interrupts. */
  TIMER0->ICR = 0x1;            /* STEP8. Clear timeout flag before start counting. */
  TIMER0->CTL |= 0x01;          /* STEP9. Enable the TimerA0 and start counting. */
  /* ------------------------ PART II (END) ------------------------ */
}

void NVIC_init(void)
{
  /* --------------------------- PART III--------------------------- */
  /* --------------------- NVIC  Configuration --------------------- */
  NVIC->IP[30] = 0 << 5;    /* STEP1A. Set IRQ30 priority to 3 */
  NVIC->ISER[0] |= 0x40080000;  /* STEP1B. Enable IRQ19 & IRQ30 */
  /* ------------------------ PART III (END) ----------------------- */
}

void TIMER0A_HANDLER(void)
{
  volatile int readback;
  if (TIMER0->RIS & 0x01)       /* STEP10. Monitor the TimerA timeout flag. */
  {
    GPIOF->DATA ^= 0x02;            /* Toggle the red LED every second. */ 
    TIMER0->ICR = 0x1;
    readback = TIMER0->ICR;
  }
  else
  {
    /*should not get here, but if we do */
    TIMER0->ICR = TIMER0->MIS;
    readback = TIMER0->ICR;
  }
}

void GPIOF_Handler(void)
{
 volatile int readback;
 
 //GPIOF->DATA |= 0x00;
 
 while (GPIOF->MIS != 0)
 {
   if (GPIOF->MIS & 0x10) /* is it SW1 (PF4)?*/
   { /* GPIOF4 pin interrupt */
     /* turn ON green LED (PD3) */
     GPIOF->DATA ^= 0x08;
     GPIOF->ICR |= 0x10; 
     readback = GPIOF->ICR; 
   }
   else if (GPIOF->MIS & 0x01) /* then it must be SW2 (PF0) */
   { /* GPIOF0 pin interrupt */
     /* turn ON blue LED (PD3) */
     GPIOF->DATA ^= 0x04;
     GPIOF->ICR |= 0x01; 
     readback = GPIOF->ICR;     
   }
   else
   { /* We should never get here */ 
     /* But if we do, clear all pending interrupts */
     GPIOF->ICR = GPIOF->MIS;
     readback = GPIOF->ICR;
   }
 }
}
/*
// 1. Pre-processor Directives Section

#include "tm4c123gh6pm.h"
#include "led.h"
#include "PB.h"
#include "port.h"
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

  while(1)
  {

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
*/
