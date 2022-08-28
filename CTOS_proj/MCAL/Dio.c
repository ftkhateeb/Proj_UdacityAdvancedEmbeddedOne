#include "Dio.h"


Dio_LevelType_e DIO_ReadPin (Dio_ChannelType_e PinId)
{ 
    Dio_LevelType_e result = Level_Low ;
    Dio_PortType_e Port = PinId / 8 ;
    Dio_PinPositionType_e Pin = PinId % 8 ;

    switch (Port)
    {
    case DIO_PORTA:
        result  = GET_BIT(GPIO_PORTA_DATA_R, Pin);
        break;
    case DIO_PORTB:
        result  = GET_BIT(GPIO_PORTB_DATA_R, Pin);
        break;
    case DIO_PORTC:
        result  = GET_BIT(GPIO_PORTC_DATA_R, Pin);
        break;

    case DIO_PORTD:
        result  = GET_BIT(GPIO_PORTD_DATA_R, Pin);
        break;

    case DIO_PORTE:
        result  = GET_BIT(GPIO_PORTE_DATA_R, Pin);
        break;

    case DIO_PORTF:
        result  = GET_BIT(GPIO_PORTF_DATA_R, Pin);
        break;

    default:
        break;
    }

    return result;
}


void DIO_WritePin(Dio_ChannelType_e PinId, Dio_LevelType_e level)
{
    Dio_PinPositionType_e Pin = PinId % 8 ;
    Dio_PortType_e Port = PinId / 8 ;

    switch (Port)
    {
    case DIO_PORTA:
        SET_BIT(GPIO_PORTA_DATA_R,Pin);
        break;
    case DIO_PORTB:
        SET_BIT(GPIO_PORTB_DATA_R,Pin);
        break;
    case DIO_PORTC:
        SET_BIT(GPIO_PORTC_DATA_R,Pin);
        break;
    case DIO_PORTD:
        SET_BIT(GPIO_PORTD_DATA_R,Pin);
        break;
    case DIO_PORTE:
        SET_BIT(GPIO_PORTE_DATA_R,Pin);
        break;
    case DIO_PORTF:
        SET_BIT(GPIO_PORTF_DATA_R,Pin);
        break;
    
    default:
        break;
    } 
    
}

void DIO_FlipPin (Dio_ChannelType_e PinId)
{
    Dio_PortType_e Port =  PinId / 8 ;
    Dio_PinPositionType_e Pin = PinId % 8 ;

    switch (Port)
    {
    case DIO_PORTA:
        TOGGLE_BIT(GPIO_PORTA_DATA_R,Pin);
        break;
    case DIO_PORTB:
        TOGGLE_BIT(GPIO_PORTB_DATA_R,Pin);
        break;
    case DIO_PORTC:
        TOGGLE_BIT(GPIO_PORTC_DATA_R,Pin);
        break;
    case DIO_PORTD:
        TOGGLE_BIT(GPIO_PORTD_DATA_R,Pin);
        break;
    case DIO_PORTE:
        TOGGLE_BIT(GPIO_PORTE_DATA_R,Pin);
        break;
    case DIO_PORTF:
        TOGGLE_BIT(GPIO_PORTF_DATA_R,Pin);
        break;
    default:
        break;
    }
}

DIO_PortLevelType DIO_ReadPort (Dio_PortType_e PortId)
{
    DIO_PortLevelType result = 0x00;
    
    switch (PortId)
    {
case DIO_PORTA:
        result = GPIO_PORTA_DATA_R ;
        break;
    case DIO_PORTB:
        result = GPIO_PORTB_DATA_R;
        break;
    case DIO_PORTC:
        result = GPIO_PORTC_DATA_R;
        break;
    case DIO_PORTD:
        result = GPIO_PORTD_DATA_R;
        break;
    case DIO_PORTE:
        result = GPIO_PORTE_DATA_R;
        break;
    case DIO_PORTF:
        result = GPIO_PORTF_DATA_R;
        break;
    default:
        break;
    }

    return result;
}

void DIO_WritePort (Dio_PortType_e PortId, DIO_PortLevelType levels)
{
    switch (PortId)
    {
    case DIO_PORTA:
        GPIO_PORTA_DATA_R = levels ;
        break;
    case DIO_PORTB:
        GPIO_PORTB_DATA_R = levels ;
        break;
    case DIO_PORTC:
        GPIO_PORTC_DATA_R = levels ;
        break;
    case DIO_PORTD:
        GPIO_PORTD_DATA_R = levels ;
        break;
    case DIO_PORTE:
        GPIO_PORTE_DATA_R = levels ;
        break;
    case DIO_PORTF:
        GPIO_PORTF_DATA_R = levels ;
        break;
    default:
        break;
    }
}

void DIO_FlipPort (Dio_PortType_e PortId)
{
    switch (PortId)
    {
    case DIO_PORTA:
        GPIO_PORTA_DATA_R = ~GPIO_PORTA_DATA_R ;
        break;
    case DIO_PORTB:
        GPIO_PORTB_DATA_R = ~GPIO_PORTB_DATA_R ;
        break;
    case DIO_PORTC:
        GPIO_PORTC_DATA_R = ~GPIO_PORTC_DATA_R ;
        break;
    case DIO_PORTD:
        GPIO_PORTD_DATA_R = ~GPIO_PORTD_DATA_R ;
        break;
    case DIO_PORTE:
        GPIO_PORTE_DATA_R = ~GPIO_PORTE_DATA_R ;
        break;
    case DIO_PORTF:
        GPIO_PORTF_DATA_R = ~GPIO_PORTF_DATA_R ;
        break;
    default:
        break;
    }
}