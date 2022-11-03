#include "NVIC.h"


void NVIC_Enable_interrupt(uint8 InterruptNum)
{
    uint8  Temp_InterruptNum = 0;

    if (InterruptNum <= 31)
    {
        Temp_InterruptNum = InterruptNum;
        SET_BIT(NVIC_EN0_R, Temp_InterruptNum);

    }
    else if ( InterruptNum <= 63)
    {
        Temp_InterruptNum = InterruptNum - 32;
        SET_BIT(NVIC_EN1_R, Temp_InterruptNum);
        
    }
    else if ( InterruptNum <= 95)
    {
        Temp_InterruptNum = InterruptNum - 64;
        SET_BIT(NVIC_EN2_R, Temp_InterruptNum);        
    }
    else if ( InterruptNum <= 127)
    {
        Temp_InterruptNum = InterruptNum - 96;
        SET_BIT(NVIC_EN3_R, Temp_InterruptNum);        
    }
    else if ( InterruptNum <= 159)
    {
        Temp_InterruptNum = InterruptNum - 128;
        SET_BIT(NVIC_EN4_R, Temp_InterruptNum);        
    }
    else
    {
        //error handling 
    }
}

void NVIC_Set_int_priority(uint8 InterruptNum, uint8 Priority);
 