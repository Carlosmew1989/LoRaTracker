/*
 * uBloxGPS.c
 *
 *  Created on: 06.01.2018
 *      Author: Carlos
 */

#include "uBloxGPS.h"
#include "debug.h"
#include "stm32l0xx_hal.h"

void GPSInitUart();
void GPSInitGPIO();

UART_HandleTypeDef GPSUartHandle;

uint8_t GPSReadBuffer[GPS_READ_BUF_SIZE];

void GPSInit() {
	GPSInitUart();
}

void GPSInitUart() {

	PRINTF("Startig GPS UART Initialization\n");

	GPSUartHandle.Instance = GPS_USART;
	GPSUartHandle.Init.BaudRate   = 9600;
	GPSUartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	GPSUartHandle.Init.StopBits   = UART_STOPBITS_1;
	GPSUartHandle.Init.Parity     = UART_PARITY_NONE;
	GPSUartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	GPSUartHandle.Init.Mode       = UART_MODE_TX_RX;

	if(HAL_UART_DeInit(&GPSUartHandle) != HAL_OK) {
		Error_Handler();
	}

	if(HAL_UART_Init(&GPSUartHandle) != HAL_OK) {
		Error_Handler();
	}

	GPSInitGPIO();

	PRINTF("GPS UART init done\n");
}

void GPSInitGPIO() {
	GPIO_InitTypeDef  GPIO_InitStruct;

	/* Enable Tx/Rx Pin clock */
	USARTx_TX_RX_CLK_ENABLE();

	/* Enable USART1 clock */
	USARTx_CLK_ENABLE();

	/* UART TX GPIO pin configuration  */
	GPIO_InitStruct.Pin       = USARTx_TX_PIN;
	GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull      = GPIO_PULLUP;
	GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = USARTx_AF;

	HAL_GPIO_Init(USARTx_TX_PIN_PORT, &GPIO_InitStruct);

	/* UART RX GPIO pin configuration  */
	GPIO_InitStruct.Pin = USARTx_RX_PIN;

	HAL_GPIO_Init(USARTx_RX_PIN_PORT, &GPIO_InitStruct);
}

void GPSRead() {
	PRINTF("GPS OUTPUT:________________________________ \n");

	while(1) {
		if(HAL_UART_Receive(&GPSUartHandle, (uint8_t *)GPSReadBuffer, GPS_READ_BUF_SIZE, 5000) != HAL_OK) {
			Error_Handler();
		}

		for(uint16_t i = 0; i < GPS_READ_BUF_SIZE; i++) {
			PRINTF("%c", GPSReadBuffer[i]);
		}

		HAL_Delay(1000);
	}


}

