/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  SYS TICK                                                     */
/*  version    :  V01                                                 */
/*  DATA       : 25/1/2022                                            */
/*********************************************************************/
#ifndef   STICK_INTERFACE_H
#define   STICK_INTERFACE_H
#include "STD_types.h"
#include "Systick_cfg.h"
#include "Bit_manipulation.h"
 // the  struct definition system timer 
typedef struct 
    {    
	volatile  uint32  STK_CTRL  ;
	volatile  uint32  STK_LOAD  ;
	volatile  uint32  STK_CURRENT   ;
}STICK_I ;
//pointer to sturct STICK_I
#define     STICK    ((STICK_I *)0xE000E010)



//the macro choise opation of clock sys tick 
#define   STICK_AHB             0
#define   STICK_AHB_DIV_4       1

// the micro of mode Interval  1- Singal 2-Periodic

#define     STICk_ModeIntervalSingal         0
#define     STICk_ModeIntervalPeriodic       1
void Systick_CallbackRegisteringFn(void (*callbackPtr)(void));
/* the function  Init the clock of systick from choose the file configuration and initalition system timer */
void SYSTICK_voidInit(void );

/* the  synchonious function counter timer  the value that as  delay  */
void MSTICK_voidSetBusyWait( uint32 capy_u32Ticks );

// the  Asynchonious function counter timer  the value that as  delay by one shoot not repated
void MSTICK_voidSetIntervalSingle(uint32 capy_u32Ticks, void (*capy_ptr)(void));

// the  Asynchonious function counter timer the value that as delay by repated
void SYSTICK_voidSetIntervalPeriodicc(uint32 capy_u32Ticks);
//the function to stop time 
void MSTICK_voidStopTimer(void);
// the function to get value of ticks elapsed form start
uint32  MSTICK_u32GetElapsedTime(void );
// the function to get value of ticks to action interrupt  flag
uint32  MSTICK_u32GetRemainingTime(void );
void SysTick_Handler(void);
#endif 
