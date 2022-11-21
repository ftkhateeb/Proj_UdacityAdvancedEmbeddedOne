
// 1. Pre-processor Directives Section

#include "tm4c123gh6pm.h"
#include "led.h"
#include "PB.h"
#include "port.h"
#include "NVIC.h"
#include "Systick.h"

int main(void)
{
  
  //Initilize GPIO
  PORT_init();
  //Initialize LEDs
  LED_Init();
  //Enable Interrupt on PORTF
  NVIC_EnableInterrupt(30);
  //Initilze SYSTICK
  SYSTICK_voidInit();
  /*
  *Registering the Callback function that should e called when 
  *Systick timer interrupt fires
  */
  Systick_CallbackRegisteringFn(&LED_update);
  /*
  *Registering the Callback function that should e called when 
  *PushButtons interrupt fires
  */
  PORT_PortFCallbackRegisteringFn(&PB_update);
  //Start Systick Timer with a period of half seconds
  SYSTICK_voidSetIntervalPeriodic(SYSTICK_THIRD_SEC);


  while(1)
  {

  }
  
}


