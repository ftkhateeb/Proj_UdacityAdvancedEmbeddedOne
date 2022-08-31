#ifndef  LEDPROJ_MCAL_PORT_PORT_H 
#define	 LEDPROJ_MCAL_PORT_PORT_H
#include "lcfg.h"
#include "tm4c123gh6pm.h"
#include "port_types.h"
#include "RAL.h"
#include "port_cfg.h"
#include "Bit_manipulation.h"

#define MAX_NUM_CHANNEL_IN_PORT 8
#define MAX_NUM_OF_PORTS 6
void PORT_clock_Init(void);
void PORT_init(void);

#endif
