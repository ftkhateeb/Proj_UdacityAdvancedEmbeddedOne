#ifndef LEDPROJ_MCAL_PORT_PORT_TYPES_H
#define LEDPROJ_MCAL_PORT_PORT_TYPES_H

#include "STD_types.h"

typedef enum
{
    PORT_PORTA_PIN0, 
    PORT_PORTA_PIN1,
    PORT_PORTA_PIN2,
    PORT_PORTA_PIN3,
    PORT_PORTA_PIN4,
    PORT_PORTA_PIN5,
    PORT_PORTA_PIN6,
    PORT_PORTA_PIN7,

    PORT_PORTB_PIN0, 
    PORT_PORTB_PIN1,
    PORT_PORTB_PIN2,
    PORT_PORTB_PIN3,
    PORT_PORTB_PIN4,
    PORT_PORTB_PIN5,
    PORT_PORTB_PIN6,
    PORT_PORTB_PIN7,



    PORT_PORTC_PIN0, 
    PORT_PORTC_PIN1,
    PORT_PORTC_PIN2,
    PORT_PORTC_PIN3,
    PORT_PORTC_PIN4,
    PORT_PORTC_PIN5,
    PORT_PORTC_PIN6,
    PORT_PORTC_PIN7,


    PORT_PORTD_PIN0, 
    PORT_PORTD_PIN1,
    PORT_PORTD_PIN2,
    PORT_PORTD_PIN3,
    PORT_PORTD_PIN4,
    PORT_PORTD_PIN5,
    PORT_PORTD_PIN6,
    PORT_PORTD_PIN7,


    PORT_PORTE_PIN0, 
    PORT_PORTE_PIN1,
    PORT_PORTE_PIN2,
    PORT_PORTE_PIN3,
    PORT_PORTE_PIN4,
    PORT_PORTE_PIN5,
    PORT_PORTE_PIN6_NA,
    PORT_PORTE_PIN7_NA,


    PORT_PORTF_PIN0, 
    PORT_PORTF_PIN1,
    PORT_PORTF_PIN2,
    PORT_PORTF_PIN3,
    PORT_PORTF_PIN4,

    Port_Channel_MaxNum

} PORT_PinType_e;

typedef enum
{   
    PORT_PORTA,
    PORT_PORTB,
    PORT_PORTC,
    PORT_PORTD,
    PORT_PORTE,
    PORT_PORTF

} PORT_PortType_e;


typedef enum
{
    PORT_Pin_Dir_Input,
    PORT_Pin_Dir_Output,

} PORT_PinDirType_e;

typedef enum 
{
    PORT_MODE_GPIO,
    PORT_MODE_UART_TX,
    PORT_MODE_UART_RX,
    PORT_MODE_SSI_CLK,
    PORT_MODE_SSI_FSS,
    PORT_MODE_SSI_RX,
    PORT_MODE_SSI_TX,
    PORT_MODE_I2C_SCL,
    PORT_MODE_I2C_SDA,
    PORT_MODE_PWM,
    PORT_MODE_CCP,
    PORT_MODE_AIN,
    PORT_MODE_CAN_RX,
    PORT_MODE_CAN_TX

} PORT_PinModeType_e;

typedef enum
{
    PORT_INTERNAL_ATTACH_NA,
    PORT_INTERNAL_ATTACH_PULL_UP_RES,
    PORT_INTERNAL_ATTACH_PULL_DOWN_RES,
    PORT_INTERNAL_ATTACH_OPEN_DRAIN
} PORT_InternalAttachType_e;

typedef enum
{
    PORT_PIN_OUTPUT_CURRENT_2mA,
    PORT_PIN_OUTPUT_CURRENT_4mA,
    PORT_PIN_OUTPUT_CURRENT_8mA

} PORT_PinOutputCurrentType_e;

typedef enum
{
    PORT_IntDisable,
    PORT_IntFallingEdge,
    PORT_IntRisingEdge,
    PORT_IntBothEdges
}PORT_IntCtrType_e;

typedef enum
{   
    PORT_PIN_UNLOCK,
    PORT_PIN_LOCK


}PORT_PinLockType_e;

typedef struct
{
    PORT_PinType_e PinId;
    PORT_PinDirType_e PinDir;
    PORT_PinModeType_e Mode;
    PORT_InternalAttachType_e InternalAttach;
    PORT_IntCtrType_e Interrupt;
    PORT_PinOutputCurrentType_e CurrentDrive;
    PORT_PinLockType_e LockStatus;
} PORT_ConfigType_S;



#endif