#include "PB.h"

 extern Port_configType PBConfig;

void PB_Init(void)
{
	
	GPIO_Init(PBConfig);
	
	
}


