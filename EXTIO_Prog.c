#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
#include"EXTIO_Inter.h"
#include"EXTIO_Config.h"
#include"EXTIO_Reg.h"
#define nul    0
volatile void ((*pf)(void))= nul;


/******************Init Interrupt**************************/
ErrorStatus EXTI0_enumInit(void)
{
	ErrorStatus error=ES_NOK;
 #if 	SENSE_MODE  ==  LOW
        CLR_BIT(MCUCR,0);
        CLR_BIT(MCUCR,1);
 #elif 	SENSE_MODE  ==  LOGIC_CHANGE
        SET_BIT(MCUCR,0);
        CLR_BIT(MCUCR,1);
 #elif 	SENSE_MODE  ==  FALLING
        CLR_BIT(MCUCR,0);
        SET_BIT(MCUCR,1);
 #elif 	SENSE_MODE  ==  RISING
        SET_BIT(MCUCR,0);
        SET_BIT(MCUCR,1);

#endif
 return error;
}

/******************Enable Interrupt**************************/

ErrorStatus EXTI0_enumEnable (void)
{
	ErrorStatus error=ES_NOK;
	SET_BIT(GICR,6);
	return error;
}

/******************Disable Interrupt**************************/

ErrorStatus EXTI0_enumDisable (void)
{
	ErrorStatus error=ES_NOK;
	CLR_BIT(GICR,6);
	return error;
}


void __vector_1()__attribute__((signal,used));
void __vector_1()
{
	pf();
}
void EXTI0_enumSetCallBack (void(*x)(void))
{
	pf=x;
}
