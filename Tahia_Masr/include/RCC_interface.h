/*****************************************************************/
/* Author 	: Essam												 */
/* Version	: V01												 */
/* Date 	: 30 March 2022										 */
/*****************************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H


#define RCC_AHP		0	
#define RCC_APB1	1	
#define RCC_APB2	2

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif