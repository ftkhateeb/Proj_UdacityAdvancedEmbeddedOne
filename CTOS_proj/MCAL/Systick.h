/**********************************************************************/
/*  name       : Ahmed Elkhateeb                                      */
/*  SW         :  SYS TICK                                                     */
/*  version    :  V01                                                 */
/*  DATA       : 25/1/2022                                            */
/*********************************************************************/
#ifndef   STICK_INTERFACE_H
#define   STICK_INTERFACE_H
#include "STD_types.h"
#include "Systick_cfg.h"
#include "Bit_manipulation.h"
#include "RAL.h"



//Macros that determine the clock source 
#define   STICK_AHB             0 //System clock
#define   STICK_AHB_DIV_4       1 //the precision internal oscillator (PIOSC)

void Systick_CallbackRegisteringFn(void (*callbackPtr)(void));
/* Driver Init */
void SYSTICK_voidInit(void );


/*function to start timer with a given number of ticks*/
void SYSTICK_voidSetIntervalPeriodicc(uint32 capy_u32Ticks);
/*IRQ Handler*/
void SysTick_Handler(void);
#endif 
