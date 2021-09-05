/*
 * APP.c
 *
 * Created: 9/5/2021 1:57:06 AM
 *  Author: Mohamed El-Kholy
 */ 
#include  	 "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/MDIO_interface.h"
#include "../EUCAL/LED/LED_interface.h"
#include "../MCAL/TIMER/Timer_interface.h"
#include "APP.h"

/* Global Variable define the State inside the ISR Function */
u8 local_u8State = 0 ;

void APP_init(void)
{
	/* Set PIN0 at PORTA as Output Pin */
	MDIO_voidSetPinDirection(GPIOA , PIN0 , HIGH) ;
	/* Initialize PIN0 at PORTA as LOW */
	MDIO_voidSetPinValue(GPIOA , PIN0 , LOW);
	/* CAll Timer Initialization With 
	* Timer 1 
	* 64 Prescaler
	* Overflow Interrupt
	* Normal Mode */
	MTimer_voidInit();
	/* Enable GIE Interrupt */
	MTimer_voidEnableGIE();
	/* Set TCNT as 500 ms Delay */
	MTimer_s8SetTCNT(49911);
	/* Set CAll Back Function */
	MTimer_voidSetCallBack(Interrupt);
}


void Interrupt (void)
{
	/* First State */	
	if (local_u8State == 0 )
	{
		/* After 500 ms LOW make Turn on the Led */
		EULED_voidLedON(GPIOA,PIN0);
		/* Make the Variable holds the value for the Next State */
		local_u8State = 1 ;
		/* Make The TCNT Register holds the value for over flow after 300 ms */
		MTimer_s8SetTCNT(56161);
	}
	/* Next State */
	else if (local_u8State==1)
	{
		/* Make The TCNT Register holds the value for over flow after 500 ms */
		MTimer_s8SetTCNT(49911);
		/* After 300 ms High make Turn Off the Led */
		MDIO_voidSetPinValue(GPIOA,PIN0,LOW);
		/* Make the Variable holds the value for the Next State */
		local_u8State = 0 ;
	}
	
}
