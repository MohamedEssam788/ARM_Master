/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 18 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
		/* Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);	
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_LOW);
	MSTK_voidSetBusyWait(100);	
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	
		/* Sleep Out Command */
	voidWriteCommand(0x11);
	
		/* Wait 150 msec*/
	MSTK_voidSetBusyWait(150000);
	
		/* Color Mode Command */
	voidWriteCommand(0x3A);
	voidWriteData	(0x05);
	
		/* Display On Command */
	voidWriteCommand(0x29);	
	

}
void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	u16 counter ;
	
		/* Set X Address */
	voidWriteCommand(0x2A);
		/* Start X Point*/
	voidWriteData(0);
	voidWriteData(0);
		/* End X Point */
	voidWriteData(0);
	voidWriteData(127);

		/* Set Y Address */
	voidWriteCommand(0x2B);
		/* Start Y Point*/
	voidWriteData(0);
	voidWriteData(0);
		/* End Y Point */
	voidWriteData(0);
	voidWriteData(159);
	
		/* RAM Write */
	voidWriteCommand(0x2C);
	
	for(counter = 0; counter <20480 ; counter++ )
	{
			/* Write the High Byte for One Pixle */
		voidWriteData( Copy_Image[counter] >> 8     );
			/* Write the Low Byte for One Pixle */
		voidWriteData( Copy_Image[counter] & 0x00ff );
	}
}


static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	
		/* Set A0 Pin to Low */
	MGPIO_voidSetPinValue(TFT_A0_PIN ,GPIO_LOW);
	
		/* Send Command Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command , &Local_u8Temp);
}


static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
		
		/* Set A0 Pin to High */
	MGPIO_voidSetPinValue(TFT_A0_PIN ,GPIO_HIGH);
		
		/* Send Data Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data , &Local_u8Temp);

}

void HTFT_voidDisplayImageOFF(void)
{
	voidWriteCommand(0x28);
}
