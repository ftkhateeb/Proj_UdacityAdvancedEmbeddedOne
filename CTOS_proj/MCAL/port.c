#include "port.h"
#include "Dio.h"
#include "port_lcfg.h"
#if 0
void PORT_clock_Init(void)
{
  //Enable clocks as per configurations
  RCGCGPIO_REG.R0 = SYSCTR_RCC_GPIO_PORTA;
  if(ENABLE == SYSCTR_RCC_GPIO_PORTA )
  {
    while((SYSCTL_PRGPIO_R & 0x00000001) == 0){};
  }
  RCGCGPIO_REG.R1 = SYSCTR_RCC_GPIO_PORTB;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTB)
  {
    while((SYSCTL_PRGPIO_R & 0x00000002) == 0){};
  }
  RCGCGPIO_REG.R2 = SYSCTR_RCC_GPIO_PORTC;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTC)
  { 
    while((SYSCTL_PRGPIO_R & 0x00000004) == 0){};

  }
  RCGCGPIO_REG.R3 = SYSCTR_RCC_GPIO_PORTD;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTD)
  {
    while((SYSCTL_PRGPIO_R & 0x00000008) == 0){};

  }
  RCGCGPIO_REG.R4 = SYSCTR_RCC_GPIO_PORTE;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTE)
  {
    while((SYSCTL_PRGPIO_R & 0x00000010) == 0){};

  }
  RCGCGPIO_REG.R5 = SYSCTR_RCC_GPIO_PORTF;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTF)
  {
    while((SYSCTL_PRGPIO_R & 0x00000020) == 0){};

  }
}
#endif

void PORT_clock_Init(void)
{ 
//Enable clocks as per configurations
  RCGCGPIO_REG.R0 = SYSCTR_RCC_GPIO_PORTA;
  if(ENABLE == SYSCTR_RCC_GPIO_PORTA )
  {
    while((SYSCTL_PRGPIO_R & 0x00000001) == 0){};
  }
  RCGCGPIO_REG.R1 = SYSCTR_RCC_GPIO_PORTB;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTB)
  {
    while((SYSCTL_PRGPIO_R & 0x00000002) == 0){};
  }
  RCGCGPIO_REG.R2 = SYSCTR_RCC_GPIO_PORTC;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTC)
  { 
    while((SYSCTL_PRGPIO_R & 0x00000004) == 0){};

  }
  RCGCGPIO_REG.R3 = SYSCTR_RCC_GPIO_PORTD;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTD)
  {
    while((SYSCTL_PRGPIO_R & 0x00000008) == 0){};

  }
  RCGCGPIO_REG.R4 = SYSCTR_RCC_GPIO_PORTE;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTE)
  {
    while((SYSCTL_PRGPIO_R & 0x00000010) == 0){};

  }
  RCGCGPIO_REG.R5 = SYSCTR_RCC_GPIO_PORTF;
  if (ENABLE == SYSCTR_RCC_GPIO_PORTF)
  {
    while((SYSCTL_PRGPIO_R & 0x00000020) == 0){};
    GPIO_PORTF_LOCK_R = 0x4C4F434B;  
    GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0 
  }
  //GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  //GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  //GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  //GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  //GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  //GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  //GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  //GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0 


}


void PORT_init(void)
{ 

    
  PORT_clock_Init();

  uint8 i = 0;
  PORT_PinType_e Pin;
  PORT_PortType_e Port;
  volatile PORT_RegType* PORT_Addr;

  for (i = 0 ; i < PORT_NUM_OF_ACTIVATED_PINS;  i++ )
  {
    Pin  = ConfigArray[i].PinId % 8 ;
    Port = ConfigArray[i].PinId / 8 ;

    switch (Port)
    {
    case PORT_PORTA:
      PORT_Addr = &PORTA_REG;
      break;
    case PORT_PORTB:
      PORT_Addr = &PORTB_REG;
      break;
    case PORT_PORTC:
      PORT_Addr = &PORTC_REG;
      break;
    case PORT_PORTD:
      PORT_Addr = &PORTD_REG;
      break;
    case PORT_PORTE:
      PORT_Addr = &PORTE_REG;
      break;
    case PORT_PORTF:
      PORT_Addr = &PORTF_REG;
    
    default:
      break;
    }

    if(ConfigArray[i].PinDir == PORT_Pin_Dir_Output )
    {
      SET_BIT(PORT_Addr->GPIODIR , Pin);
    }
    else
    {
      CLR_BIT(PORT_Addr->GPIODIR , Pin);
    }
    
    if(ConfigArray[i].Mode == PORT_MODE_GPIO)
    {
      CLR_BIT(PORT_Addr->GPIOAFSEL , Pin);
    }
    else
    {
      SET_BIT(PORT_Addr->GPIOAFSEL , Pin);
      PORT_Addr->GPIOPCTL |= ( ConfigArray[i].Mode << (Pin*4) );
    }

    /* set Interrupt configuration */
    if(ConfigArray[i].Interrupt == PORT_IntDisable)
    {
        CLR_BIT(PORT_Addr->GPIOIM, Pin);
    }
    else
    {
        SET_BIT(PORTA_REG.GPIOIM, Pin);
        if(ConfigArray[i].Interrupt == PORT_IntRisingEdge)
        {
            SET_BIT(PORT_Addr->GPIOIEV,Pin);
        }
        else if(ConfigArray[i].Interrupt == PORT_IntFallingEdge)
        {
            CLR_BIT(PORT_Addr->GPIOIEV,Pin);
        }
        else if(ConfigArray[i].Interrupt == PORT_IntBothEdges)
        {
            SET_BIT(PORT_Addr->GPIOIBE,Pin);
        }
    }

        /* set Internal Attachment configuration */
    if(ConfigArray[i].InternalAttach == PORT_INTERNAL_ATTACH_PULL_UP_RES)
    {
        SET_BIT(PORT_Addr->GPIOPUR,Pin);
    }else if(ConfigArray[i].InternalAttach == PORT_INTERNAL_ATTACH_PULL_DOWN_RES)
    {
        SET_BIT(PORT_Addr->GPIOPDR,Pin);
    }else if(ConfigArray[i].InternalAttach == PORT_INTERNAL_ATTACH_OPEN_DRAIN)
    {
        SET_BIT(PORT_Addr->GPIOODR,Pin);
    }

    /*set current strength configuration */
    if(ConfigArray[i].CurrentDrive == PORT_PIN_OUTPUT_CURRENT_2mA)
    {
        SET_BIT(PORT_Addr->GPIODR2R,Pin);
    }else if(ConfigArray[i].CurrentDrive == PORT_PIN_OUTPUT_CURRENT_4mA)
    {
        SET_BIT(PORT_Addr->GPIODR4R,Pin);
    }else if(ConfigArray[i].CurrentDrive == PORT_PIN_OUTPUT_CURRENT_8mA)
    {
        SET_BIT(PORT_Addr->GPIODR8R,Pin);
    }

    if(ConfigArray[i].Mode != PORT_MODE_AIN )
    {
        /* enable digital */
        SET_BIT(PORT_Addr->GPIODEN,Pin);
        /*disable ADC */
        CLR_BIT(PORT_Addr->GPIOADCCTL,Pin);
    }
    else
    {
        /* disable digital */
        CLR_BIT(PORT_Addr->GPIODEN,Pin);
        /* enable ADC */
        SET_BIT(PORT_Addr->GPIOADCCTL,Pin);
    }

  }
  
}

#if 0

void PORT1_init(void)
{
	SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
	while((SYSCTL_PRGPIO_R & 0x00000020) == 0){};
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0  
}
#endif
