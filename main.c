#include<util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
/***********************DIO*******************/
#include"DIO_register.h"
#include"DIO_interface.h"
/*********************EXT_INT_0*******************/
#include"EXTIO_Reg.h"
#include"EXTIO_Config.h"
#include"EXTIO_Inter.h"

void EXT_ISRINT_0 (void);



void main ()
{
	DIO_enumSetPinDirection( DIO_U8_PORT_D ,DIO_U8_PIN2,DIO_U8_INPUT );//INT0_Signl
	DIO_enumSetPinValue    ( DIO_U8_PORT_D ,DIO_U8_PIN2,DIO_U8_HIGH  );

	DIO_enumSetPinDirection( DIO_U8_PORT_B ,DIO_U8_PIN5,DIO_U8_OUTPUT);//INT0_LED Indicator

	DIO_enumSetPinDirection( DIO_U8_PORT_A ,DIO_U8_PIN7,DIO_U8_OUTPUT);//Main_LED Indicator

	EXTI0_enumInit();

	//PIE enable
	EXTI0_enumEnable ();
	EXTI0_enumSetCallBack(EXT_ISRINT_0);
	//ENABLE GIF
	SET_BIT(SREG,7);



	while (1)
	{
		DIO_enumSetPinValue( DIO_U8_PORT_A ,DIO_U8_PIN7,DIO_U8_HIGH  );
		_delay_ms(1000);
		DIO_enumSetPinValue( DIO_U8_PORT_A ,DIO_U8_PIN7,DIO_U8_LOW   );
		_delay_ms(1000);
	}


}


void EXT_ISRINT_0 (void) // pass num of interrupt from vector table to isr
	{
		DIO_enumSetPinValue( DIO_U8_PORT_B,DIO_U8_PIN5,DIO_U8_HIGH   );
		_delay_ms(1000);
		DIO_enumSetPinValue( DIO_U8_PORT_B,DIO_U8_PIN5,DIO_U8_LOW    );
		_delay_ms(1000);
	}


