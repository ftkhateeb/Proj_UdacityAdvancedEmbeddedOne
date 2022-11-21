/**********************************************************************/
/*  name       : Ahmed Elkhateeb                                       */
/*  SW         :  SYStem Timer                                                      */
/*  version    :  V01                                                 */
/*  DATA       : 15/11/2022                                            */
/*********************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**     \file  Systick.c
 *      \brief  System Timer systick  
 *
 *      \details  Driver to configure system timer 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "tm4c123gh6pm.h"

#include "Systick.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
static void (*STICK_CallBack)(void);
//the define call back  globel variable    (pointer to function)  
void Systick_CallbackRegisteringFn (void (*callbackPtr)(void))
{
    STICK_CallBack =  callbackPtr;
}

/*******************************************************************************************************************************
 *     the APIs supported by this driver  for  more information about the APIs check the function definitions
 */

/******************************************************************************
* \Syntax          : void MSTICK_voidInit(void )
* \Description     : initialize  the clock of systick from choise the file configration 
*                     Disable the sys tick system & Disable  interrupt the sys tick 
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : NOna     
* \Parameters (out): nona
* \Return value:   : None
*******************************************************************************/

void SYSTICK_voidInit(void )
{
	
	#if CLOCK_SYS_TICK== STICK_AHB
        SET_BIT(NVIC_ST_CTRL_R, 2);
        NVIC_ST_CURRENT_R = 0;
	#elif CLOCK_SYS_TICK == STICK_AHB_DIV_4

        STICK -> STK_CTRL =0x00000000;	
 
	#else 
		#error "the error choise to file config "
	
	
	#endif 
}                       


/******************************************************************************
* \Syntax          : void MSTICK_voidSetIntervalPeriodic(uint32 capy_u32Ticks, void (*capy_ptr)(void))
* \Description     : the Asynchonious function counter timer  the value that as  delay by repated 
*             
* \Sync\Async      : ASynchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : capy_u32Ticks     
* \Parameters (out): void (*capy_ptr)(void)
* \Return value:   : None
*******************************************************************************/
void SYSTICK_voidSetIntervalPeriodic(uint32 ticks)
{
    SET_BIT(NVIC_ST_CTRL_R,0);
    SET_BIT(NVIC_ST_CTRL_R,1);
	NVIC_ST_RELOAD_R  = ticks;

}



/******************************************************************************
* \Syntax          : uint32  MSTICK_u32GetRemainingTime(void )
* \Description     : the  function to handler ISR system timer sys_Tick
*             
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : none    
* \Parameters (out): none
* \Return value:   : none
*******************************************************************************/
void SysTick_Handler(void)
{

	// call the nafication function 
	STICK_CallBack();

}
/**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/
