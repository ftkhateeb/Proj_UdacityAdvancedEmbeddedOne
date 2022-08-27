#include "Dio.h"


Dio_LevelType_e DIO_ReadPin (Dio_ChannelType_e PinId)
{ 
    Dio_LevelType_e result = Level_Low ;
    Dio_PortType_e PortId = PinId / 8 ;
    Dio_ChannelType_e Pin = PinId % 8 ;

    switch (PortId)
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
}
void DIO_WritePin(Dio_ChannelType_e PinId, Dio_LevelType_e level);
void DIO_FlipPin (Dio_ChannelType_e PinId);
uint8 DIO_ReadPort (Dio_PortType_e PortId);
void DIO_WritePort (Dio_PortType_e PortId, uint8 levels);
void DIO_FlipPort (Dio_PortType_e PortId);