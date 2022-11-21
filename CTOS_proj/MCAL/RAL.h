#ifndef LEDPROJ_SERVICE_RAL_H
#define LEDPROJ_SERVICE_RAL_H
#include "STD_types.h"


typedef struct 
    {    
	volatile  uint32  STK_CTRL  ;
	volatile  uint32  STK_LOAD  ;
	volatile  uint32  STK_CURRENT   ;
}STICK_I ;
//pointer to sturct STICK_I
#define     STICK    ((STICK_I *)0xE000E010)

typedef struct
{
    uint32 R0:1;
    uint32 R1:1;
    uint32 R2:1;
    uint32 R3:1;
    uint32 R4:1;
    uint32 R5:1;
    uint32 R6:1;
    uint32 R7:1;

}RCGC_TagType;

#define RCGCGPIO_REG   (*((volatile RCGC_TagType*)0x400FE608))

typedef struct 
{
    uint32 Interrupt_0:1;
    uint32 Interrupt_1:1;
    uint32 Interrupt_2:1;
    uint32 Interrupt_3:1;
    uint32 Interrupt_4:1;
    uint32 Interrupt_5:1;
    uint32 Interrupt_6:1;
    uint32 Interrupt_7:1;
    uint32 Interrupt_8:1;
    uint32 Interrupt_9:1;
    uint32 Interrupt_10:1;
    uint32 Interrupt_11:1;
    uint32 Interrupt_12:1;
    uint32 Interrupt_13:1;
    uint32 Interrupt_14:1;
    uint32 Interrupt_15:1;
    uint32 Interrupt_16:1;
    uint32 Interrupt_17:1;
    uint32 Interrupt_18:1;
    uint32 Interrupt_19:1;
    uint32 Interrupt_20:1;
    uint32 Interrupt_21:1;
    uint32 Interrupt_22:1;
    uint32 Interrupt_23:1;
    uint32 Interrupt_24:1;
    uint32 Interrupt_25:1;
    uint32 Interrupt_26:1;
    uint32 Interrupt_27:1;
    uint32 Interrupt_28:1;
    uint32 Interrupt_29:1;
    uint32 Interrupt_30:1;
    uint32 Interrupt_31:1;
}NVIC_EN0_INT_NUM_t;

#define NVIC_MY_EN0_R (*((volatile NVIC_EN0_INT_NUM_t*) 0xE000E100)) 

typedef struct 
{
    uint32 Interrupt_32:1;
    uint32 Interrupt_33:1;
    uint32 Interrupt_34:1;
    uint32 Interrupt_35:1;
    uint32 Interrupt_36:1;
    uint32 Interrupt_37:1;
    uint32 Interrupt_38:1;
    uint32 Interrupt_39:1;
    uint32 Interrupt_40:1;
    uint32 Interrupt_41:1;
    uint32 Interrupt_42:1;
    uint32 Interrupt_43:1;
    uint32 Interrupt_44:1;
    uint32 Interrupt_45:1;
    uint32 Interrupt_46:1;
    uint32 Interrupt_47:1;
    uint32 Interrupt_48:1;
    uint32 Interrupt_49:1;
    uint32 Interrupt_50:1;
    uint32 Interrupt_51:1;
    uint32 Interrupt_52:1;
    uint32 Interrupt_53:1;
    uint32 Interrupt_54:1;
    uint32 Interrupt_55:1;
    uint32 Interrupt_56:1;
    uint32 Interrupt_57:1;
    uint32 Interrupt_58:1;
    uint32 Interrupt_59:1;
    uint32 Interrupt_60:1;
    uint32 Interrupt_61:1;
    uint32 Interrupt_62:1;
    uint32 Interrupt_63:1;
}NVIC_EN1_INT_NUM_t;

#define NVIC_MY_EN2_R (*((volatile NVIC_EN1_INT_NUM_t*) 0xE000E104)

#define NVIC_PRI(x)        (*(( __vo uint32_t *)(0xE000E400+(x*4))))

typedef struct
{
    uint32 GPIODATA    ;
    uint32 GPIODIR     ;
    uint32 GPIOIS      ;
    uint32 GPIOIBE     ;
    uint32 GPIOIEV     ;
    uint32 GPIOIM      ;
    uint32 GPIORIS     ;
    uint32 GPIOMIS     ;
    uint32 GPIOICR     ;
    uint32 GPIOAFSEL   ; /*offset : 0x420 -> 424 */

    uint8 Reserved_2[0xDC];
    uint32 GPIODR2R    ; /*offset : 0x500 */
    uint32 GPIODR4R    ;
    uint32 GPIODR8R    ;
    uint32 GPIOODR     ;
    uint32 GPIOPUR     ;
    uint32 GPIOPDR     ;
    uint32 GPIOSLR     ;
    uint32 GPIODEN     ;
    uint32 GPIOLOCK    ;
    uint32 GPIOCR      ;
    uint32 GPIOAMSEL   ;
    uint32 GPIOPCTL    ;
    uint32 GPIOADCCTL  ;
    uint32 GPIODMACTL  ;
}PORT_RegType;

#define PORTA_REG     (*((volatile PORT_RegType*)0x400043FC))
#define PORTB_REG     (*((volatile PORT_RegType*)0x400053FC))
#define PORTC_REG     (*((volatile PORT_RegType*)0x400063FC))
#define PORTD_REG     (*((volatile PORT_RegType*)0x400073FC))
#define PORTE_REG     (*((volatile PORT_RegType*)0x400243FC))
#define PORTF_REG     (*((volatile PORT_RegType*)0x400253FC))
#endif