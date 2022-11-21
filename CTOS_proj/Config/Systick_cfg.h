#ifndef   STICK_CONFIG_H
#define   STICK_CONFIG_H

 /*  Options clock_sys_tick :
                              1-  STICK_AHB     
                              2-  STICK_AHB_DIV_4     */   
/*STICK_AHB -> that system clock  microcontrol 
*STICK_AHB_DIV_4  ->that system clock  internal 16Mhz      that clock will be =4 mhz */

#define    CLOCK_SYS_TICK   STICK_AHB
#define    SYSTICK_HALF_SEC 15999999
#define    SYSTICK_TIME SYSTICK_HALF_SEC
#endif