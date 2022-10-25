/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 18 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void	MUART1_voidInit		(  void	 ) ;
void	MUART1_voidTransmit (u8 arr[]) ;
u8 		MUART1_u8Receive	(  void	 ) ;

#endif