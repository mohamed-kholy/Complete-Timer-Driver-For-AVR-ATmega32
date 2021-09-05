
#include "../../LIB/STD_TYPES.h"
#include "../../MCAl/DIO/MDIO_interface.h"
#include "LED_interface.h"

void EULED_voidLedON(u8 copy_u8Port, u8 copy_u8PinNum ) 
{
	if ( ((copy_u8Port == GPIOA) || (copy_u8Port == GPIOB) || (copy_u8Port == GPIOC) ||(copy_u8Port == GPIOD) ) && ((copy_u8PinNum >=0) && (copy_u8PinNum <=7)))
		MDIO_voidSetPinValue(copy_u8Port,copy_u8PinNum,HIGH);
	else
	{
		/* Error Handler */
	}
}
void EULED_voidLedOFF (u8 copy_u8Port, u8 copy_u8PinNum ) 
{
	if ( ((copy_u8Port == GPIOA) || (copy_u8Port == GPIOB) || (copy_u8Port == GPIOC) ||(copy_u8Port == GPIOD) ) && ((copy_u8PinNum >=0) && (copy_u8PinNum <=7)))
		MDIO_voidSetPinValue(copy_u8Port,copy_u8PinNum,LOW);
	else
	{
		/* Error Handler */
	}
}
void EULED_voidLedToggle(u8 copy_u8Port, u8 copy_u8PinNum ) 
{
		if ( ((copy_u8Port == GPIOA) || (copy_u8Port == GPIOB) || (copy_u8Port == GPIOC) ||(copy_u8Port == GPIOD) ) && ((copy_u8PinNum >=0) && (copy_u8PinNum <=7)))
		MDIO_voidTogglePin(copy_u8Port,copy_u8PinNum);
	else
	{
		/* Error Handler */
	}
} 