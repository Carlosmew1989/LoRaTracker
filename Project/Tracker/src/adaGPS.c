/*
 * adaGPS.c
 *
 *  Created on: 27.01.2018
 *      Author: Carlos
 */

#include <stdbool.h>

#include "adaGPS.h"
#include "debug.h"
#include "stm32l0xx_hal.h"
#include "timeServer.h"
#include "minmea.h"
#include "delay.h"

#define LINE_BUF_SIZE 100
#define NMEA_MAX_MSG_COUNT 15

#define UART_TIMEOUT 1000 	/* [ms] */

#define MAX_CMD_RETRYS 10

void GPSUartInit();
UART_HandleTypeDef GPSUartHandle;

void parseNMEA(char *nmeaSentence, GPSData_t *gpsData);

bool GPSSendCommand(uint8_t *command, uint16_t len);
bool sendPMTK(uint8_t *cmd, uint16_t cmdLen);
bool checkForAck(uint16_t cmdNr);

static uint8_t calcPMTKCrc(uint8_t *pmtkCmd, uint16_t cmdLen);

static TimerEvent_t GPSRxTimeoutTimer;
static void OnGPSRxTimeout();

static void onUartRxTimeout( void );

char PMTKAckMsg[] = "$PMTK001";

uint8_t PMTKColdStart[] = "$PMTK103*30\r\n";

/* Set the device in normal mode */
uint8_t PMTKPeriodicToNormal[] = "$PMTK225,0*%02X\r\n";

/* [Message id], [SV], [SNR], [extension threshold], [extension gap]*/
uint8_t PMTKPeriodicConf[] = "$PMTK223,1,25,180000,60000*%02X\r\n";

/* [Message id], [Type], [Run time], [Sleep time], [Second run time], [Second sleep time] */
uint8_t PMTKPeriodicCmd[] = "$PMTK225,1,60000,480000,120000,480000*%02X\r\n";

/* [Message id], [set/query], [easy on/off] */
uint8_t PMTKEnableEasy[] = "$PMTK869,1,1*%02X\r\n";

uint8_t charBuf = 0;
uint8_t lineBuf[LINE_BUF_SIZE] = {0};
uint8_t nmeaBuf[NMEA_MAX_MSG_COUNT][LINE_BUF_SIZE] = {0};

uint8_t charCount = 0;
uint8_t nmeaCount = 0;

bool GPSDataReadyFlag = false;
bool UartTxCpltFlag = false;
bool uartRxTimeout = false;

static void OnGPSRxTimeout() {
	GPSDataReadyFlag = true;
}

void GPSReadData(GPSData_t *gpsData) {

	for(uint8_t i = 0; i < nmeaCount; i++) {
		printf("[%d] 	%s", i, nmeaBuf[i]);

		parseNMEA((char *)nmeaBuf[i], gpsData);

		memset(nmeaBuf[i], 0, LINE_BUF_SIZE);
	}

	nmeaCount = 0;

	printf("\n\n");
}

void parseNMEA(char *nmeaSentence, GPSData_t *gpsData) {
	switch(minmea_sentence_id(nmeaSentence, false)) {
	case MINMEA_SENTENCE_RMC: {
		struct minmea_sentence_rmc frame;
		if (minmea_parse_rmc(&frame, nmeaSentence)) {
			gpsData->time = frame.time.hours * 10000;
			gpsData->time += frame.time.minutes * 100;
			gpsData->time += frame.time.seconds;

			gpsData->date = frame.date.day * 10000;
			gpsData->date += frame.date.month * 100;
			gpsData->date += frame.date.year;

			if(frame.valid) {
				gpsData->fixQuality = 1;
			}

			gpsData->latitude = frame.latitude.value;
			gpsData->longitude = frame.longitude.value;

			gpsData->speed = frame.speed.value;
			gpsData->speedScale = frame.speed.scale;
		}else {
			printf("$xxRMC sentence is not parsed\n");
		}
	} break;

	case MINMEA_SENTENCE_GGA: {
		struct minmea_sentence_gga frame;
		if (minmea_parse_gga(&frame, nmeaSentence)) {
			gpsData->time = frame.time.hours * 10000;
			gpsData->time += frame.time.minutes * 100;
			gpsData->time += frame.time.seconds;

			gpsData->fixQuality = frame.fix_quality;

			gpsData->latitude = frame.latitude.value;
			gpsData->longitude = frame.longitude.value;

			gpsData->satsFix = frame.satellites_tracked;

			gpsData->altitudeSee = frame.altitude.value;
			gpsData->altitude = frame.height.value;

			gpsData->hdop = frame.hdop.value;
		}else {
			printf("$xxGGA sentence is not parsed\n");
		}

	} break;

	case MINMEA_SENTENCE_GSA: {
		struct minmea_sentence_gsa frame;
		if(minmea_parse_gsa(&frame, nmeaSentence)) {
			gpsData->satsFix = 0U;
			for(uint8_t i = 0; i < 12; i++) {
				if(frame.sats[i] > 0) gpsData->satsFix++;
			}

			gpsData->hdop = frame.hdop.value;
			gpsData->pdop = frame.pdop.value;
			gpsData->vdop = frame.vdop.value;
		}else {
			printf("$xxGSA sentence is not parsed\n");
		}

	} break;

	case MINMEA_SENTENCE_GSV: {
		struct minmea_sentence_gsv frame;
		if(minmea_parse_gsv(&frame, nmeaSentence)) {
			gpsData->satsVis = frame.total_sats;
		}

	} break;

	case MINMEA_SENTENCE_GLL: {

	} break;

	case MINMEA_SENTENCE_GST: {

	} break;

	case MINMEA_SENTENCE_VTG: {

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

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
	if(UartHandle->Instance == USART1) {
		if(GPSRxTimeoutTimer.IsRunning) {
			TimerStop(&GPSRxTimeoutTimer);
		}

		lineBuf[charCount] = charBuf;
		charCount++;

		if(charBuf == 0x0A) {
			lineBuf[charCount] = '\0';

			if(nmeaCount < NMEA_MAX_MSG_COUNT) {
				memcpy(nmeaBuf[nmeaCount], lineBuf, charCount);
				nmeaCount++;

				if(nmeaCount == NMEA_MAX_MSG_COUNT) {
					GPSDataReadyFlag = true;
				}
			}

			memset(lineBuf, 0, LINE_BUF_SIZE);
			charCount = 0;
		}

		if(HAL_UART_Receive_IT(UartHandle, (uint8_t *)&charBuf, 1) != HAL_OK) {
			Error_Handler();
		}

		TimerStart(&GPSRxTimeoutTimer);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle) {
	/* Set transmission flag: transfer complete */
	UartTxCpltFlag = true;
}

void GPSInit() {
	bool ret = false;
	uint16_t len = 0;

	GPSUartInit();

	printf("GPSInit: Sending command %s", (char *)PMTKPeriodicToNormal);
	len = SIZE_OF(PMTKPeriodicToNormal);
	ret = GPSSendCommand(PMTKPeriodicToNormal, len);
	if(!ret) {
		Error_Handler();
	}

	printf("GPSInit: Sending command %s", (char *)PMTKEnableEasy);
	len = SIZE_OF(PMTKEnableEasy);
	ret = GPSSendCommand(PMTKEnableEasy, len);
	if(!ret) {
		Error_Handler();
	}

	return;

	printf("GPSInit: Sending command %s", (char *)PMTKPeriodicConf);
	len = SIZE_OF(PMTKPeriodicConf);
	ret = GPSSendCommand(PMTKPeriodicConf, len);
	if(!ret) {
		Error_Handler();
	}

	printf("GPSInit: Sending command %s", (char *)PMTKPeriodicCmd);
	len = SIZE_OF(PMTKPeriodicCmd);
	ret = GPSSendCommand(PMTKPeriodicCmd, len);
	if(!ret) {
		Error_Handler();
	}
}

bool GPSSendCommand(uint8_t *command, uint16_t len) {
	uint16_t trys = 0;
	uint8_t newLen = 0, crc = 0;
	uint8_t cmd[100];
	bool ret = false;

	printf("len1: %u \n", len);
	crc = calcPMTKCrc(command, len);
	snprintf((char *)cmd, 100, (const char *)command, crc);
	newLen = strlen((const char *)cmd);

	printf("new len: %u\n", newLen);
	ret = sendPMTK(cmd, newLen);
	while(!ret && trys < MAX_CMD_RETRYS) {
		printf("GPSSendCommand: Retry %u\n", trys+1);
		ret = sendPMTK(cmd, newLen);
		trys++;
	}
	if(!ret){
		printf("GPSSendCommand: Reached max cmd resend trys!\n");
		return false;
	}

	return true;
}

bool sendPMTK(uint8_t *cmd, uint16_t cmdLen) {
	uint16_t cmdNr = 0;
	static TimerEvent_t uartRxTimeoutTimer;

	TimerInit(&uartRxTimeoutTimer, onUartRxTimeout);
	TimerSetValue(&uartRxTimeoutTimer, UART_TIMEOUT);

	/* Transmit command in interrupt mode */
	if(HAL_UART_Transmit_IT(&GPSUartHandle, (uint8_t*)cmd, cmdLen)!= HAL_OK) {
		printf("sendPMTK: UART transmit error!\n");
		return false;
	}

	/* Wait for tx complete interrupt */
	while(!UartTxCpltFlag) {}

	UartTxCpltFlag = false;

	/* Check if UART is ready, if not abort ongoing reception */
	if(GPSUartHandle.RxState != HAL_UART_STATE_READY) {
		HAL_UART_AbortReceive_IT(&GPSUartHandle);
	}

	/* Put UART in reception mode */
	if(HAL_UART_Receive_IT(&GPSUartHandle, (uint8_t *)&charBuf, 1) != HAL_OK) {
		printf("sendPMTK: UART receive error!\n");
		return false;
	}

	/* Start timeout timer, so we dont wait for ever */
	TimerStart(&uartRxTimeoutTimer);
	/* Wait for answer from GPS */
	while(!GPSDataReadyFlag) {
		if(uartRxTimeout) {
			HAL_UART_AbortReceive_IT(&GPSUartHandle);
			printf("sendPMTK: Uart rx timeout!\n");
			uartRxTimeout = false;
			return false;
		}
	}
	TimerStop(&uartRxTimeoutTimer);

	GPSDataReadyFlag = false;

	/* Parse out the number of the command we sent */
	sscanf((const char *) cmd, "%*[^0123456789]%hu", &cmdNr);

	return checkForAck(cmdNr);
}

bool checkForAck(uint16_t cmdNr) {
	uint16_t buf = 0;
	char *p;
	bool succsess = false;

	/* Check message buffer */
	for(uint8_t i = 0; i < nmeaCount; i++) {
		printf("[%d] 	%s", i, nmeaBuf[i]);

		/* Get message ID */
		p = strtok((char *) nmeaBuf[i], ",*");
		if (p == NULL) continue;

		/* Look for PMTK ACK message $PMTK001 */
		if(strncmp(PMTKAckMsg, p, strlen(PMTKAckMsg)) == 0) {
			/* Get the message that was acked */
			p = strtok(NULL, ",*");
			if(p == NULL) continue;

			sscanf(p, "%hu", &buf);

			printf("sendPMTK: Received ack for message: %d\n", buf);

			if(cmdNr == buf) {
				/* Get the ACK status */
				p = strtok(NULL, ",*");
				if(p == NULL) continue;

				sscanf(p, "%hu", &buf);

				/* Check the status of the ACK */
				if(buf == 0U) {
					printf("sendPMTK: Invalid command/packet!\n");
				}else if(buf == 1U) {
					printf("sendPMTK: Unsupported command/packet!\n");
				}else if(buf == 2U) {
					printf("sendPMTK: Valid command/packet but action failed!\n");
				}else if(buf == 3U) {
					printf("sendPMTK: Command succeeded\n");
					succsess = true;
				}
			}
		}

		memset(nmeaBuf[i], 0, LINE_BUF_SIZE);
	}

	nmeaCount = 0;

	return succsess;
}

static void onUartRxTimeout( void ) {
	uartRxTimeout = true;
}

void GPSUartInit() {
	printf("Startig GPS UART Initialization\n");

	GPSUartHandle.Instance 		  = GPS_USART;
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

	//	if (HAL_UART_Receive_IT(&GPSUartHandle, (uint8_t *)&charBuf, 1) != HAL_OK) {
	//		Error_Handler();
	//	}

	printf("GPS UART init done\n");
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart) {

	/*##-1- Enable peripherals and GPIO Clocks #################################*/

	/* Enable USART clock */
	USARTX_CLK_ENABLE();

	/*##-2- Configure peripheral GPIO ##########################################*/
	vcom_IoInit( );

	GPSIoInit();
}

void GPSIoInit() {
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

static uint8_t calcPMTKCrc(uint8_t *pmtkCmd, uint16_t cmdLen) {
	uint16_t i;
	uint8_t crc = 0;

	/* Calc CRC over everything between $ and * */
	for(i = 1; i < cmdLen; i ++) {
		if(pmtkCmd[i] == 0x2A) break;
		crc = (crc ^ pmtkCmd[i]);
	}

	return crc;
}
