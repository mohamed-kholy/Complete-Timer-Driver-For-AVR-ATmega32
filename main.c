/*
 * Timer Interrupt Task.c
 *
 * Created: 9/5/2021 1:55:21 AM
 * Author : Mohamed El-Kholy
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/MDIO_interface.h"
#include "EUCAL/LED/LED_interface.h"
#include "MCAL/TIMER/Timer_interface.h"

/* Define CPU Cycle As 2 MHZ */
#define F_CPU 2000000UL

int main(void)
{
	/* Call APP Initialization Function */
    APP_init();
    while (1) 
    {
    }
}

