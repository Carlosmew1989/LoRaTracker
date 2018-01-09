/*
 * uBloxGPS.c
 *
 *  Created on: 06.01.2018
 *      Author: Carlos
 */

#include <stdbool.h>

#include "uBloxGPS.h"
#include "debug.h"
#include "stm32l0xx_hal.h"
#include "timeServer.h"

#include "minmea.h"

#define LINE_BUF_SIZE 100
#define NMEA_MAX_MSG_COUNT 15

void GPSUartInit();
void GPSIoInit(UART_HandleTypeDef *huart);

UART_HandleTypeDef GPSUartHandle;

static TimerEvent_t GPSRxTimeoutTimer;
static void OnGPSRxTimeout();

void parseNMEA(char *nmeaSentence, GPSData_t *gData);

uint8_t charBuf = 0;
uint8_t lineBuf[LINE_BUF_SIZE] = {0};
uint8_t nmeaBuf[NMEA_MAX_MSG_COUNT][LINE_BUF_SIZE] = {0};

uint8_t charCount = 0;
uint8_t nmeaCount = 0;

uint8_t GPSDataReadyFlag = 0;

/**
 * @brief UART MSP Initialization
 *        This function configures the hardware resources used in this example:
 *           - Peripheral's clock enable
 *           - Peripheral's GPIO Configuration
 *           - NVIC configuration for UART interrupt request enable
 * @param huart: UART handle pointer
 * @retval None
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{

	/*##-1- Enable peripherals and GPIO Clocks #################################*/

	/* Enable USART clock */
	USARTX_CLK_ENABLE();

	/*##-2- Configure peripheral GPIO ##########################################*/
	vcom_IoInit( );

	GPSIoInit(huart);

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
	if(UartHandle->Instance == USART1) {
		if(GPSRxTimeoutTimer.IsRunning) {
			TimerStop(&GPSRxTimeoutTimer);
		}

		lineBuf[charCount] = charBuf;
		charCount++;

		if(charBuf == 0x0A) {
			lineBuf[charCount] = '\0';

			memcpy(nmeaBuf[nmeaCount], lineBuf, charCount);
			nmeaCount++;

			memset(lineBuf, 0, LINE_BUF_SIZE);
			charCount = 0;

			if(nmeaCount == NMEA_MAX_MSG_COUNT) {
				GPSDataReadyFlag = 1;
			}
		}

		HAL_UART_Receive_IT(UartHandle, (uint8_t *)&charBuf, 1);

		TimerStart(&GPSRxTimeoutTimer);
	}
}

void GPSReadData(GPSData_t *gData) {

	for(uint8_t i = 0; i < nmeaCount; i++) {
		printf("[%d] 	%s", i, nmeaBuf[i]);

		parseNMEA((char *)nmeaBuf[i], gData);

		memset(nmeaBuf[i], 0, LINE_BUF_SIZE);
	}

	nmeaCount = 0;

	printf("\n\n");
}

void parseNMEA(char *nmeaSentence, GPSData_t *gData) {
	switch(minmea_sentence_id(nmeaSentence, false)) {
	case MINMEA_SENTENCE_RMC: {
		struct minmea_sentence_rmc frame;
		if (minmea_parse_rmc(&frame, nmeaSentence)) {
			gData->time = frame.time.hours * 10000;
			gData->time += frame.time.minutes * 100;
			gData->time += frame.time.seconds;

			gData->date = frame.date.day * 10000;
			gData->date += frame.date.month * 100;
			gData->date += frame.date.year;

			gData->fixQuality = 1;

			gData->latitude = frame.latitude.value;
			gData->longitude = frame.longitude.value;

			gData->speed = frame.speed.value;
			gData->speedScale = frame.speed.scale;
		}else {
			printf("$xxRMC sentence is not parsed\n");
		}
	} break;

	case MINMEA_SENTENCE_GGA: {
		struct minmea_sentence_gga frame;
		if (minmea_parse_gga(&frame, nmeaSentence)) {
			gData->time = frame.time.hours * 10000;
			gData->time += frame.time.minutes * 100;
			gData->time += frame.time.seconds;

			gData->fixQuality = frame.fix_quality;

			gData->latitude = frame.latitude.value;
			gData->longitude = frame.longitude.value;

			gData->nSatellites = frame.satellites_tracked;
		}else {
			printf("$xxGGA sentence is not parsed\n");
		}

	} break;

	case MINMEA_SENTENCE_GSA: {

	} break;

	case MINMEA_SENTENCE_GLL: {

	} break;

	case MINMEA_SENTENCE_GST: {

	} break;

	case MINMEA_SENTENCE_VTG: {

	} break;

	case MINMEA_SENTENCE_GSV: {

	} break;

	case MINMEA_SENTENCE_ZDA: {

	} break;

	case MINMEA_INVALID: {
		printf("NMEA sentence is not valid!\n");
	} break;

	default: {
		printf("NMEA sentence was not parsed!\n");
	}break;

	}

}

static void OnGPSRxTimeout() {
	GPSDataReadyFlag = 1;
}

void GPSInit() {
	GPSUartInit();
}

void GPSUartInit() {

	printf("Startig GPS UART Initialization\n");

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

	TimerInit(&GPSRxTimeoutTimer, OnGPSRxTimeout);

	TimerSetValue(&GPSRxTimeoutTimer, 50);

	if (HAL_UART_Receive_IT(&GPSUartHandle, (uint8_t *)&charBuf, 1) != HAL_OK) {
		Error_Handler();
	}

	printf("GPS UART init done\n");
}

void GPSIoInit(UART_HandleTypeDef *huart) {
	GPIO_InitTypeDef  GPIO_InitStruct;

	/* Enable Tx/Rx Pin clock */
	GPS_USART_TX_RX_CLK_ENABLE();

	/* Enable USART1 clock */
	GPS_USART_CLK_ENABLE();

	/* UART TX GPIO pin configuration  */
	GPIO_InitStruct.Pin       = GPS_USART_TX_PIN;
	GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull      = GPIO_PULLUP;
	GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPS_USART_AF;

	HAL_GPIO_Init(GPS_USART_TX_PIN_PORT, &GPIO_InitStruct);

	/* UART RX GPIO pin configuration  */
	GPIO_InitStruct.Pin = GPS_USART_RX_PIN;
	HAL_GPIO_Init(GPS_USART_RX_PIN_PORT, &GPIO_InitStruct);

	/* NVIC for USART, to catch the TX complete */
	HAL_NVIC_SetPriority(GPS_USART_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(GPS_USART_IRQn);

}
