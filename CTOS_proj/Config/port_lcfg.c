#include "port_types.h"
#include "port_cfg.h"

PORT_ConfigType_S ConfigArray[PORT_NUM_OF_ACTIVATED_PINS]=
{

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*      PIN                 Direction                   Mode                    InternalAttach                      Interrupt                           CurrentDrive                             LockStatus         */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
   {    PORT_PORTF_PIN0,    PORT_Pin_Dir_Input,         PORT_MODE_GPIO,         PORT_INTERNAL_ATTACH_PULL_UP_RES,    PORT_IntFallingEdge,               PORT_PIN_OUTPUT_CURRENT_2mA,            PORT_PIN_UNLOCK     },
   {    PORT_PORTF_PIN1,    PORT_Pin_Dir_Output,        PORT_MODE_GPIO,         PORT_INTERNAL_ATTACH_NA,             PORT_IntDisable,                   PORT_PIN_OUTPUT_CURRENT_2mA,            PORT_PIN_UNLOCK     },
   {    PORT_PORTF_PIN4,    PORT_Pin_Dir_Input,         PORT_MODE_GPIO,         PORT_INTERNAL_ATTACH_PULL_UP_RES,    PORT_IntFallingEdge,               PORT_PIN_OUTPUT_CURRENT_2mA,            PORT_PIN_UNLOCK     }


};