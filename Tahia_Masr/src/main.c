/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: Essam
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "UART_interface.h"

#include "TFT_interface.h"
#include "image.h"

void main (void)
{
	/* RCC Initialization */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , 2);		/* GPIOA */
	MRCC_voidEnableClock(RCC_APB2 ,12);		/* SPI1  */
	MRCC_voidEnableClock(RCC_APB2 ,14);		/* UART1  */

		/* PIN Initialization */
	/* SPI PINS */
	MGPIO_voidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PUSH_PULL);	      /* RST */
	MGPIO_voidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PUSH_PULL);  	  /* A0  */
	MGPIO_voidSetPinDirection(GPIOA , PIN5 , OUTPUT_SPEED_10MHZ_AF_PUSH_PULL);	  /* CLK */
	MGPIO_voidSetPinDirection(GPIOA , PIN7 , OUTPUT_SPEED_10MHZ_AF_PUSH_PULL);    /* MOSI*/

	/* UART PINS */
	MGPIO_voidSetPinDirection(GPIOA , PIN9  ,OUTPUT_SPEED_50MHZ_AF_PUSH_PULL ); /* TX */
	MGPIO_voidSetPinDirection(GPIOA , PIN10 ,    INPUT_FLOATING 		  ); /* RX */

	/* STK Init */
	MSTK_voidInit();

		/* SPI Init */
	MSPI1_voidInit();

	/* UART Init */
	MUART1_voidInit();

		/* TFT Init */
	HTFT_voidInit();

	u8 x ;

	while(1)
	{
		x = MUART1_u8Receive();
				if (x == 'e')
				{
					/* TFT Init */
					HTFT_voidInit();

					/* Display Image */
					HTFT_voidDisplayImage(image);
				}
				else if(x == 'k')
				{
					HTFT_voidDisplayImageOFF();
				}
	}
}
