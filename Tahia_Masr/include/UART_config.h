/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 18 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H


#define UART1_STATUS            UART1_ENABLE		/* Options :  UART1_DISABLE
															      URT1_ENABLE	   	   */

#define UART1_BAUD_RATE         (u32)9600 			/* Select BAUD RATE */


#define UART1_WORD_LENGTH       8BIT_WORD_LENGTH	/* Options :  8BIT_WORD_LENGTH
															      9BIT_WORD_LENGTH	   */
																  
#define UART1_PARITY            PARITY_DISABLE		/* Options :  EVEN_PARITY
															      ODD_PARITY
																  PARITY_DISABLE	   */
																  
#define UART1_INTERRUPT         INT_DISABLE			/* Options :  INT_DISABLE
															      TXE_INT_ENABLE
																  TCE_INT_ENABLE 
																  RXNE_INT_ENABLE	  	*/

#define UART1_TRANSMITTER       TRANSMITTER_ENABLE	/* Options :  TRANSMITTER_ENABLE
															      TRANSMITTER_DISABLE 	*/
																  
#define UART1_RECEIVER          RECEIVER_ENABLE		/* Options :  RECEIVER_ENABLE
															      RECEIVER_DISABLE		*/

#define UART1_STOP_BITS         ONE_STOP_BIT 		/* Options :  ONE_STOP_BIT
															      HALF_STOP_BIT
																  TWO_STOP_BIT 
																  ONE_AND_HALF_STOP_BIT	  */
																  

#endif