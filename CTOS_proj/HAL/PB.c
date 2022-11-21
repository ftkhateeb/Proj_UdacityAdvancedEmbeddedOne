#include "PB.h"
#include "led.h"

PB_STATE PB_GetButtonState(PB_ID ID)
{
    Dio_LevelType_e Input = Level_Low;
    PB_STATE output  = BUTTON_RELEASED;

    switch (ID)
    {
    case PB_ONE_ID:
        Input = DIO_ReadPin(PB_ONE);
        if (Input == Level_Low )
        {
            output  =  BUTTON_PRESSED;
        }
        else
        {
            output =  BUTTON_RELEASED;
        }
        return output;
        break;
    
    case PB_TWO_ID:
        Input = DIO_ReadPin(PB_TWO);
        if (Input == Level_Low )
        {
            output  =  BUTTON_PRESSED;
        }
        else
        {
            output =  BUTTON_RELEASED;
        }
        return output;
        break;
    default:
        
    }
}



void PB_update (void)
{
    /*If Interrupt is caused by the first Switch*/
    if ( GPIO_PORTF_MIS_R & 0x10)
    {
        Led_on_time ++;
        /*clear Interrupt flag*/
        GPIO_PORTF_ICR_R |= 0x10;
        /*increase LED on time by 1 sec (3* thirds of sec)*/
        Led_on_time_ThirdSec += 3;
        if (Led_on_time > 15)
        {
            Led_on_time = 0;
            Led_on_time_ThirdSec = 0;
        }
       
    }

    /*Same logic but for the other switch*/
    else if ( GPIO_PORTF_MIS_R & 0x01)
    {
        Led_off_time ++;
        GPIO_PORTF_ICR_R |= 0x01;
        Led_off_time_ThirdSec += 3;
        if (Led_off_time > 15)
        {
            Led_off_time = 0;
            Led_off_time_ThirdSec = 0;
        }
             
    }
    else
    {

    }
}

