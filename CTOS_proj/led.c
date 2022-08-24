#include "led.h"

extern Port_configType LedConfig ;


	 void LED_Init(void)
{
		GPIO_Init(LedConfig);

}


