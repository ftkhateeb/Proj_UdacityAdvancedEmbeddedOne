#include "led.h"

 uint32 Led_on_time_ThirdSec = INITIAL_LED_ON_TIME_SEC*3 ;
 uint32 Led_off_time_ThirdSec = INITIAL_LED_OFF_TIME_SEC*3 ;
 uint32 Led_on_time = INITIAL_LED_ON_TIME_SEC ;
 uint32 Led_off_time = INITIAL_LED_OFF_TIME_SEC ;
void LED_Init(void)
{
	LED_On(RED_LED_ID);
	LED_Off(GREEN_LED_ID);
	LED_Off(BLUE_LED_ID);

}


void LED_On(LED_ID ID)
{
	switch (ID)
	{
		case RED_LED_ID:
			DIO_WritePin(GREEN_LED_PIN, Level_Low);
			DIO_WritePin(BLUE_LED_PIN, Level_Low);
			DIO_WritePin(RED_LED_PIN, Level_High);
			break;

		case BLUE_LED_ID:
			DIO_WritePin(GREEN_LED_PIN, Level_Low);
			DIO_WritePin(RED_LED_PIN, Level_Low);
			DIO_WritePin(BLUE_LED_PIN, Level_High);
			break;

		case GREEN_LED_ID:
			DIO_WritePin(BLUE_LED_PIN, Level_Low);
			DIO_WritePin(RED_LED_PIN, Level_Low);
			DIO_WritePin(GREEN_LED_PIN, Level_High);
			break;
		default :


	}
}

void LED_Off(LED_ID ID)
{
	switch (ID)
	{
		case RED_LED_ID:
			DIO_WritePin(RED_LED_PIN, Level_Low);
			break;

		case BLUE_LED_ID:
			DIO_WritePin(BLUE_LED_PIN, Level_Low);
			break;

		case GREEN_LED_ID:
			DIO_WritePin(GREEN_LED_PIN, Level_Low);
			break;
		default :


	}
}

void LED_update(void)
{
  static Led_status_e led_status = LED_ON;
  static uint8 actual_on_time_thirdsec = 0;
  static uint8 actual_off_time_thirdsec = 0;
  
  /* if previous state of LED is ON*/	
  if (led_status == LED_ON )
  {
	  /*If the LED didn't spend the required time while being ON*/
    if (actual_on_time_thirdsec < Led_on_time_ThirdSec )
    {
	  /*Increase the actual time passed while being on, don't change LED state*/
      actual_on_time_thirdsec++;
    }
	 /* if the LED did spend the required time while being ON*/
    else
    {
	  /*change led state to OFF*/
      LED_Off(RED_LED_ID);
      led_status =  LED_OFF;
	  /*reset the Actual time spent while being on counter*/
      actual_on_time_thirdsec = 0;
    }
  }

  /*Same mechanism as above but for the OFF state*/

  if (led_status == LED_OFF )
  {
    if(actual_off_time_thirdsec < Led_off_time_ThirdSec)
    {
        actual_off_time_thirdsec++;

    }
    else
    {
      LED_On(RED_LED_ID);
      led_status =  LED_ON;
      actual_off_time_thirdsec = 0;
    }
  }

}