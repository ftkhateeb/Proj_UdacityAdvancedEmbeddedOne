/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <NVIC.H>
 *       Module:  -MCAL
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef NVIC_H
#define NVIC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Bit_manipulation.h"
#include "tm4c123gh6pm.h"
#include "STD_types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define NVIC_PRIORITY_GROUP_8_SUBGROUP_1                     0x4
#define NVIC_PRIORITY_GROUP_1_SUBGROUP_8                     0x7
#define NVIC_PRIORITY_GROUP_4_SUBGROUP_2                     0x5
#define NVIC_PRIORITY_GROUP_2_SUBGROUP_4                     0x6


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
     /* make sure the following parameters should be visible to static code
     * InterruptNum
     * ENable\Disable
     * Priority Group
     * Sub-priority Group
     * */
    uint8 InterrNum;
    uint8 PriorityGP;
    uint8 PrioritySubGP;
}NVIC_Cfg;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const NVIC_Cfg NVIC_PCfg[NVIC_NUM_OF_ENABLED_INTERRUPT];

extern const uint8 NVIC_SUB_GP_Cfg;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void NVIC_Enable_interrupt(uint8 InterruptNum);
void NVIC_Disable_interrupt(uint8 InterruptNum);
void NVIC_CLR_PENDING_FLAG(uint8 InterruptNum);

void NVIC_Set_int_priority(uint8 InterruptNum, uint8 Priority);
 
#endif  /* NVIC_H */

/**********************************************************************************************************************
 *  END OF FILE: NVIC.h
 *********************************************************************************************************************/