/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 18 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void	MUART1_voidInit		(  void	 ) 
{
	/* Baudrate 9600 =>   BRR = 0x341*/
	MUART1 -> BRR = 0x341 ; 
	
	/* Baudrate 115200 => BRR =  */
	
		/* 1- Enable RX      */
	SET_BIT(MUART1 -> CR1 , 2 );
	
		/* 2- Enable TX      */
	SET_BIT(MUART1 -> CR1 , 3 );
	
		/* 3- Enable UART    */
	SET_BIT(MUART1 -> CR1 , 13);
		
		/* 4- CLR Status REG */
	MUART1 -> SR = 0 ; 
		
}


void	MUART1_voidTransmit (u8 arr[])
{
	u8 i =0;
	while( arr[i] != '\0' )
	{
		MUART1 -> DR = arr[i];
		
			while(GET_BIT( MUART1 -> SR , 6) == 0);
			
			/* Wait till transmission is complete */
		//while( ( (MUART1 -> SR) & 0x40 ) == 0 );
		i++;
	}
	
} 

u8 		MUART1_u8Receive	(  void	 ) 
{
	u8 Loc_u8ReceivedData = 0;
		/* 1- Wait till Receive Complete */
	while( ( GET_BIT( (MUART1 -> SR) , 5)  ) == 0 );
	Loc_u8ReceivedData = MUART1 -> DR;
	return (Loc_u8ReceivedData);
}
