#ifndef LEDPROJ_MCAL_DIO_DIO_H
#define LEDPROJ_MCAL_DIO_DIO_H
#include "Dio_types.h"
#include "Bit_manipulation.h"
#include "tm4c123gh6pm.h"

Dio_LevelType_e DIO_ReadPin (Dio_ChannelType_e PinId);
void DIO_WritePin(Dio_ChannelType_e PinId, Dio_LevelType_e level);
void DIO_FlipPin (Dio_ChannelType_e PinId);
DIO_PortLevelType DIO_ReadPort (Dio_PortType_e PortId);
void DIO_WritePort (Dio_PortType_e PortId, DIO_PortLevelType levels);
void DIO_FlipPort (Dio_PortType_e PortId);


#endif	
