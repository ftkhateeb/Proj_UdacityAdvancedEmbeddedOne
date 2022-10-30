#include "PB.h"

 //extern Port_configType PBConfig;

void PB_Init(void)
{
	
	
	
}

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

