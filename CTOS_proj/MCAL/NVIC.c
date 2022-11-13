#include "NVIC.h"


void NVIC_EnableInterrupt(uint8 InterruptNum)
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
void NVIC_DisableInterrupt(uint8 Interrupt_Num)
{
    uint8 temp_Int_num = 0;
    if (Interrupt_Num <= 31)
    {
        temp_Int_num = Interrupt_Num;
        SET_BIT(NVIC_DIS0_R , temp_Int_num );

    }
    else if(Interrupt_Num <= 63 )
    {
        temp_Int_num = Interrupt_Num - 32 ;
        SET_BIT(NVIC_DIS1_R , temp_Int_num );

    }
    else if (Interrupt_Num <= 95)
    {
        temp_Int_num = Interrupt_Num - 64;
        SET_BIT(NVIC_DIS2_R , temp_Int_num );
    }
    else if (Interrupt_Num <= 127 )
    {
         temp_Int_num = Interrupt_Num - 96;
        SET_BIT(NVIC_DIS3_R , temp_Int_num );
    }
    else if (Interrupt_Num <= 159)
    {
        temp_Int_num = Interrupt_Num - 128;
        SET_BIT(NVIC_DIS4_R , temp_Int_num );
    }
    else
    {
        //error handling
    }

}

void NVIC_ClrPendingFlag(uint8 InterruptNum)
{
    uint8  Temp_InterruptNum = 0;

    if (InterruptNum <= 31)
    {
        Temp_InterruptNum = InterruptNum;
        SET_BIT(NVIC_UNPEND0_R, Temp_InterruptNum);

    }
    else if ( InterruptNum <= 63)
    {
        Temp_InterruptNum = InterruptNum - 32;
        SET_BIT(NVIC_UNPEND0_R, Temp_InterruptNum);
        
    }
    else if ( InterruptNum <= 95)
    {
        Temp_InterruptNum = InterruptNum - 64;
        SET_BIT(NVIC_UNPEND1_R, Temp_InterruptNum);        
    }
    else if ( InterruptNum <= 127)
    {
        Temp_InterruptNum = InterruptNum - 96;
        SET_BIT(NVIC_UNPEND2_R, Temp_InterruptNum);        
    }
    else if ( InterruptNum <= 159)
    {
        Temp_InterruptNum = InterruptNum - 128;
        SET_BIT(NVIC_UNPEND3_R, Temp_InterruptNum);        
    }
    else
    {
        //error handling 
    }
}


