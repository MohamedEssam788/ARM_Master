/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 17 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

	/* Write the Slave PIN in a pair PORT ,PIN */
#define 	MSPI1_SLAVE_PIN 	GPIOA,PIN0

#define 	MSP1_STATUS          MSPI_ENABLE
	
#define 	MSPI1_CLOCK_MODE     MSPI_MODE3
	
#define 	MSPI1_MASTER_SLAVE   MSPI_MASTER
	
#define 	MSPI1_PRESCALLER     MSPI_FPCLK_DIVIDED_BY_2
	
#define 	MSPI1_DATA_ORDER     MSPI_MSB_FIRST
	
#define 	MSPI1_SS_MANAGE      HW_SLAVE_MANAGEMENT
	
#define 	MSPI1_DATA_SIZE      MSPI_8BIT_DATA
	
#define 	MSPI1_INT_STATUS     MSPI_INT_DISABLE

#endif