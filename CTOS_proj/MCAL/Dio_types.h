#ifndef LEDPROJ_MCAL_DIO_DIO_TYPESH
#define LEDPROJ_MCAL_DIO_DIO_TYPESH

#include "STD_types.h"

typedef enum
{
    Dio_PORTA_PIN0, 
    Dio_PORTA_PIN1,
    Dio_PORTA_PIN2,
    Dio_PORTA_PIN3,
    Dio_PORTA_PIN4,
    Dio_PORTA_PIN5,
    Dio_PORTA_PIN6,
    Dio_PORTA_PIN7,

    Dio_PORTB_PIN0,
    Dio_PORTB_PIN1,
    Dio_PORTB_PIN2,
    Dio_PORTB_PIN3,
    Dio_PORTB_PIN4,
    Dio_PORTB_PIN5,
    Dio_PORTB_PIN6,
    Dio_PORTB_PIN7,


    Dio_PORTC_PIN0,
    Dio_PORTC_PIN1,
    Dio_PORTC_PIN2,
    Dio_PORTC_PIN3,
    Dio_PORTC_PIN4,
    Dio_PORTC_PIN5,
    Dio_PORTC_PIN6,
    Dio_PORTC_PIN7,

    Dio_PORTD_PIN0,
    Dio_PORTD_PIN1,
    Dio_PORTD_PIN2,
    Dio_PORTD_PIN3,
    Dio_PORTD_PIN4,
    Dio_PORTD_PIN5,
    Dio_PORTD_PIN6,
    Dio_PORTD_PIN7,


    Dio_PORTE_PIN0,
    Dio_PORTE_PIN1,
    Dio_PORTE_PIN2,
    Dio_PORTE_PIN3,
    Dio_PORTE_PIN4,
    Dio_PORTE_PIN5,
    Dio_PORTE_PIN6_NA,
    Dio_PORTE_PIN7_NA,

    Dio_PORTF_PIN0,
    Dio_PORTF_PIN1,
    Dio_PORTF_PIN2,
    Dio_PORTF_PIN3,
    Dio_PORTF_PIN4

}Dio_ChannelType_e ;

typedef enum
{
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD,
    DIO_PORTE,
    DIO_PORTF

}Dio_PortType_e;

typedef enum
{
    Level_Low,
    Level_High

}Dio_LevelType_e;

typedef uint32 DIO_PortLevelType;

#endif

