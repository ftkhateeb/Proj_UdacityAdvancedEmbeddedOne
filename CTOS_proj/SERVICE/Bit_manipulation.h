#ifndef LEDPROJ_SERVICE_LEDMAN_H
#define LEDPROJ_SERVICE_LEDMAN_H

#include "STD_types.h"


#define SET_BIT(REG,BIT) REG |= ((uint32)1 << BIT) 
#define CLR_BIT(REG,BIT) REG &= ~ ((uint32)1 << BIT)
#define TOGGLE_BIT(REG,BIT) REG ^= ((uint32)1 << BIT)
#define GET_BIT(REG,BIT) ((REG >> BIT) & ((uint32)0x01))
#define GET_REG(BASE_ADDR, REG_TYPE, REG_OFFSET)                (*((volatile REG_TYPE*)(BASE_ADDR+REG_OFFSET)))

#endif