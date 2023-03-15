/*************************************************/
/*************************************************/
/********* Author: Ahmed Abdallah ****************/
/*********      LAYER: MCAL      *****************/
/*********      SWC: ADC         ****************/
/*********      DATE: 12/3/2023  *****************/
/*************************************************/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"


static u8*ADC_pu8Reading=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;
static u8 ADC_u8BusyState=IDLE;


void ADC_voidInit(void)
{
	/*Voltage Reference Selection */
#if V_REF==AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif V_REF==AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif V_REF==I_V
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "Wrong V_REF configuration option"
#endif

	/*Check Left adjust result enable initial state*/
#if LEFT_ADJUST==ADC_8_BIT
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif LEFT_ADJUST==ADC_10_BIT
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong LEFT_ADJUST configuration option"
#endif

	/*Check Peripheral ADC enable initial state*/
#if ADC_STATE==ADC_ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif ADC_STATE==ADC_DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error "Wrong ADC_STATE configuration option"
#endif

	/*ADC Prescaler Selection*/

	/*Clear First 3_bit in ADCSRA register */
	ADCSRA&=ADC_PRISCALER_MASK;
	/*Set First 3_bit in ADCSRA register to select Division Factor r between the system clock frequency and the input clock to the ADC*/
	ADCSRA|=ADC_PRISCALER;

}





u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u8*Copy_pu8Reading)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=OK;
	if(ADC_u8BusyState==IDLE)
	{
		ADC_u8BusyState=BUSY;
		/*Choose Channel of ADC*/

		/*Clear First 4_bit in ADMUX register */
		ADMUX&=ADC_ADMUX_MASK;
		/*SET the required Channel into the MUX bits */
		ADMUX|=Copy_u8Channel;

		/*Start Conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0&&Local_u32Counter!=ADC_u32TIMEOUT)
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter==ADC_u32TIMEOUT)
		{
			//loop broken cause the timeout is reached
			Local_u8ErrorState=NOK;
		}
		else
		{
			//Loop is broken cause of the rising of ADC Flag
			*Copy_pu8Reading=ADCH;

			ADC_u8BusyState=IDLE;
		}

	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}

	return Local_u8ErrorState;
}



u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u8 *Copy_pu8Reading,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(ADC_u8BusyState==IDLE)
	{
		ADC_u8BusyState=BUSY;
		if(Copy_pu8Reading==NULL||Copy_pvNotificationFunc==NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			ADC_pu8Reading=Copy_pu8Reading;
			ADC_pvCallBackNotificationFunc=Copy_pvNotificationFunc;
			/*Clear First 4_bit in ADMUX register */
			ADMUX&=ADC_ADMUX_MASK;
			/*SET the required Channel into the MUX bits */
			ADMUX|=Copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*enable ADC INT*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);


		}
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}

	return Local_u8ErrorState;

}

void __vector_21 (void) __attribute__((signal));
void __vector_21 (void)
{
	/*Read ADC result*/
	*ADC_pu8Reading=ADCH;
	/*MAke ADC Sate IDLE*/
	ADC_u8BusyState=IDLE;
	/*Invoke the call back notification function*/
	ADC_pvCallBackNotificationFunc();
	/*Disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
