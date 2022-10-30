#include "led.h"


void LED_Init(void)
{
	DIO_WritePin(Dio_PORTF_PIN1, Level_Low);
	DIO_WritePin(Dio_PORTF_PIN2, Level_Low);
	DIO_WritePin(Dio_PORTF_PIN3, Level_Low);
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

