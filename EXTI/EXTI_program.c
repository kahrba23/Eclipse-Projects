/**************************************************/
/**************************************************/
/********* Author: Ahmed Abdallah *****************/
/*********      LAYER: MCAL       *****************/
/*********      SWC: External INT           *******/
/**************************************************/
/**************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
/*Global Pointer To Function to hold INT0 ISR address*/
void (*EXTI_pvInt0Func)(void)=NULL;
/*Global Pointer To Function to hold INT1 ISR address*/
void (*EXTI_pvInt1Func)(void)=NULL;
void EXTI_voidInt0Init(void)
{
	/*Check Sense Control*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error"WRONG INT0_SENSE Configuration Option"
#endif
	/*Check Peripheral interrupt enable initial state*/
#if INT0_INIT_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INIT_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error"WRONG INT0_INIT_STATE Configuration Option"
#endif
}



void EXTI_voidInt1Init(void)
{
	/*Check Sense Control*/
#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error"WRONG INT1_SENSE Configuration Option"
#endif
	/*Check Peripheral interrupt enable initial state*/
#if INT1_INIT_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INIT_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error"WRONG INT1_INIT_STATE Configuration Option"
#endif
}



u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_ErrorState=OK;
	if(Copy_u8Sense==LOW_LEVEL)
	{
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(Copy_u8Sense==ON_CHANGE)
	{
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(Copy_u8Sense==FALLING_EDGE)
	{
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(Copy_u8Sense==RISING_EDGE )
	{
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	}
	else Local_ErrorState=NOK;

	return Local_ErrorState;
}



u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_ErrorState=OK;
	if(Copy_u8Sense==LOW_LEVEL)
	{
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	}
	else if(Copy_u8Sense==ON_CHANGE)
	{
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	}
	else if(Copy_u8Sense==FALLING_EDGE)
	{
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	}
	else if(Copy_u8Sense==RISING_EDGE )
	{
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	}
	else Local_ErrorState=NOK;

	return Local_ErrorState;
}



u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_ErrorState=OK;
	if(Copy_u8Int==INT0) SET_BIT(GICR,GICR_INT0);
	else if(Copy_u8Int==INT1) SET_BIT(GICR,GICR_INT1);
	else Local_ErrorState=NOK;
	return Local_ErrorState;
}



u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_ErrorState=OK;
	if(Copy_u8Int==INT0) CLR_BIT(GICR,GICR_INT0);
	else if(Copy_u8Int==INT1) CLR_BIT(GICR,GICR_INT1);
	else Local_ErrorState=NOK;
	return Local_ErrorState;
}


u8 EXTI_u8IntSetCallBack(u8 Copy_u8Int,void(*Copy_pvIntFunc)(void))
{
	u8 Local_ErrorState=OK;
	if(Copy_u8Int==INT0&&Copy_pvIntFunc!=NULL)
	{
		EXTI_pvInt0Func=Copy_pvIntFunc;
	}
	else if(Copy_u8Int==INT1&&Copy_pvIntFunc!=NULL)
	{
		EXTI_pvInt1Func=Copy_pvIntFunc;
	}
	else
	{
		Local_ErrorState=NULL_POINTER;
	}

	return Local_ErrorState;
}

/*ISR of INT0*/
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*DO nothing*/
	}

}
/*ISR of INT1*/
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func!=NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/*DO nothing*/
	}

}
