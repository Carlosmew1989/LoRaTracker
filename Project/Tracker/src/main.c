/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech

Description: Generic lora driver implementation

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis, Gregory Cristian and Wael Guibene
 */
/******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @version V1.1.2
 * @date    08-September-2017
 * @brief   this is the main!
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V.
 * All rights reserved.</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted, provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of other
 *    contributors to this software may be used to endorse or promote products
 *    derived from this software without specific written permission.
 * 4. This software, including modifications and/or derivative works of this
 *    software, must execute solely and exclusively on microcontroller or
 *    microprocessor devices manufactured by or for STMicroelectronics.
 * 5. Redistribution and use of this software other than as permitted under
 *    this license is void and will automatically terminate your rights under
 *    this license.
 *
 * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
 * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
 * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "hw.h"
#include "low_power.h"
#include "lora.h"
#include "bsp.h"
#include "timeServer.h"
#include "vcom.h"
#include "version.h"

#include "adaGPS.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/*!
 * Defines the application data transmission duty cycle. Value in [ms].
 */
#define APP_TX_DUTYCYCLE                        10000//5*60*1000

#define BURST_DUTYCYCLE							5 * 60 * 1000
#define BURST_DURATION 							1 * 60 * 1000
/*!
 * LoRaWAN Adaptive Data Rate
 * @note Please note that when ADR is enabled the end-device should be static
 */
#define LORAWAN_ADR_ON                           DISABLE
/*!
 * LoRaWAN confirmed messages
 */
#define LORAWAN_CONFIRMED_MSG                    DISABLE
/*!
 * LoRaWAN application port
 * @note do not use 224. It is reserved for certification
 */
#define LORAWAN_APP_PORT                            210
/*!
 * Number of trials for the join request.
 */
#define JOINREQ_NBTRIALS                            15

/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* call back when LoRa will transmit a frame*/
static void LoraTxData( lora_AppData_t *AppData, FunctionalState* IsTxConfirmed);

/* call back when LoRa has received a frame*/
static void LoraRxData( lora_AppData_t *AppData);

/* Private variables ---------------------------------------------------------*/
/* load call backs*/
static LoRaMainCallback_t LoRaMainCallbacks ={ HW_GetBatteryLevel,
		HW_GetUniqueId,
		HW_GetRandomSeed,
		LoraTxData,
		LoraRxData};

/*!
 * Specifies the state of the application LED
 */
static uint8_t AppLedStateOn = RESET;

static TimerEvent_t txBurstTimer;
static void onTxBurst( void );

static TimerEvent_t txBurstEndTimer;
static void onTxBurstEnd( void );

/*!
 * Timer to handle the application Tx Led to toggle
 */
static TimerEvent_t TxLedTimer;
static void OnTimerLedEvent( void );

/* !
 *Initialises the Lora Parameters
 */
static  LoRaParam_t LoRaParamInit= {TX_ON_TIMER,
		APP_TX_DUTYCYCLE,
		CLASS_A,
		LORAWAN_ADR_ON,
		DR_5,
		LORAWAN_PUBLIC_NETWORK,
		JOINREQ_NBTRIALS};

GPSData_t gpsData = {0};

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main( void ) {
	bool devIsJoined = false;
	float speedKmh = 0.0;

	/* STM32 HAL library initialization*/
	HAL_Init( );

	/* Configure the system clock*/
	SystemClock_Config( );

	/* Configure the debug mode*/
	DBG_Init( );

	/* Configure the hardware*/
	HW_Init( );

	/* USER CODE BEGIN 1 */
	GPSInit();

	/* USER CODE END 1 */

	/* Configure the Lora Stack*/
	lora_Init( &LoRaMainCallbacks, &LoRaParamInit);

	TimerInit(&txBurstEndTimer, onTxBurstEnd);
	TimerSetValue(&txBurstEndTimer, BURST_DURATION);

	TimerInit(&txBurstTimer, onTxBurst);
	TimerSetValue(&txBurstTimer, BURST_DUTYCYCLE);

	bool timerStarted = false;

	/* main loop*/
	while(1) {
		/* run the LoRa class A state machine*/
		lora_fsm( );

		if( lora_getDeviceState() == DEVICE_STATE_SEND) {
			devIsJoined = true;
			LED_On(LED2);
		}

//		if(devIsJoined && !timerStarted) {
//			TimerStart(&txBurstTimer);
//			timerStarted = true;
//		}

		/* USER CODE BEGIN 2 */
		if(devIsJoined && GPSDataReadyFlag) {

			memset((void *)&gpsData, 0, sizeof(gpsData));

			GPSReadData(&gpsData);

			if(gpsData.fixQuality > 0) {
				LED_On(LED3);
				printf("Got fix!\n");
				printf("Time: %lu --- Date: %lu\n", gpsData.time, gpsData.date);
				printf("Lat.: %ld --- Lon.: %ld\n", gpsData.latitude, gpsData.longitude);
				printf("Fix quality: %u --- Satellites tracked: %u\n", gpsData.fixQuality, gpsData.satsFix);

				speedKmh = ((float)gpsData.speed/(float)gpsData.speedScale) * 1.852;
				printf("Speed (Knots): %d --- SpeedScale (Knots): %u --- Speed km/h: %f\n", gpsData.speed, gpsData.speedScale, speedKmh);
			}else {
				LED_Off(LED3);
			}

			GPSDataReadyFlag = false;
		}
		/* USER CODE END 2 */
	}
}

static void onTxBurst() {
	setTxDutyCycleTime(5000);

	TimerStart(&txBurstEndTimer);
}

static void onTxBurstEnd( void ) {
	setTxDutyCycleTime(BURST_DUTYCYCLE);

	TimerStart(&txBurstTimer);
}

static void LoraTxData( lora_AppData_t *AppData, FunctionalState* IsTxConfirmed) {
	/* USER CODE BEGIN 3 */
	uint32_t byte = 0;

	TimerInit(&TxLedTimer, OnTimerLedEvent);

	TimerSetValue(&TxLedTimer, 200);

	LED_On(LED1);

	TimerStart(&TxLedTimer);

	AppData->Port = LORAWAN_APP_PORT;

	*IsTxConfirmed =  LORAWAN_CONFIRMED_MSG;

	if(gpsData.latitude <= 0xF ) {
		AppData->Buff[byte++] = 0x00;
		AppData->Buff[byte++] = 0x00;
		AppData->Buff[byte++] = 0x00;

		AppData->Buff[byte] = (gpsData.latitude << 4) & 0xFF;
	}else if(gpsData.latitude <= 0xFFF) {
		AppData->Buff[byte++] = 0x00;
		AppData->Buff[byte++] = 0x00;

		AppData->Buff[byte++] = (gpsData.latitude >> 4) & 0xFF;
		AppData->Buff[byte] = (gpsData.latitude << 4) & 0xFF;
	}else if( gpsData.latitude <= 0xFFFFF ) {
		AppData->Buff[byte++] = 0x00;

		AppData->Buff[byte++] = (gpsData.latitude >> 12) & 0xFF;
		AppData->Buff[byte++] = (gpsData.latitude >> 4) & 0xFF;
		AppData->Buff[byte] = (gpsData.latitude << 4) & 0xFF;
	}else if( gpsData.latitude <= 0x55D4A80 ) { // 0x55D4A80 = Lat 90� 00' 00''
		AppData->Buff[byte++] = (gpsData.latitude >> 20) & 0xFF;
		AppData->Buff[byte++] = (gpsData.latitude >> 12) & 0xFF;
		AppData->Buff[byte++] = (gpsData.latitude >> 4) & 0xFF;
		AppData->Buff[byte] = (gpsData.latitude << 4) & 0xFF;
	}

	if(gpsData.longitude <= 0xFF) {
		AppData->Buff[byte++] &= 0xF0;
		AppData->Buff[byte++] = 0x00;
		AppData->Buff[byte++] = 0x00;

		AppData->Buff[byte++] = gpsData.longitude & 0xFF;
	}else if(gpsData.longitude <= 0xFFFF) {
		AppData->Buff[byte++] &= 0xF0;
		AppData->Buff[byte++] = 0x00;

		AppData->Buff[byte++] = (gpsData.longitude >> 8) & 0xFF;
		AppData->Buff[byte++] = gpsData.longitude & 0xFF;
	}else if(gpsData.longitude <= 0xFFFFFF) {
		AppData->Buff[byte++] &= 0xF0;

		AppData->Buff[byte++] = (gpsData.longitude >> 16) & 0xFF;
		AppData->Buff[byte++] = (gpsData.longitude >> 8) & 0xFF;
		AppData->Buff[byte++] = gpsData.longitude & 0xFF;
	}else if(gpsData.longitude <= 0xABA9500) { // 0xABA9500 = LON 180� 00' 00''

		AppData->Buff[byte++] &= (gpsData.longitude >> 24) & 0xFF;
		AppData->Buff[byte++] = (gpsData.longitude >> 16) & 0xFF;
		AppData->Buff[byte++] = (gpsData.longitude >> 8) & 0xFF;
		AppData->Buff[byte++] = gpsData.longitude & 0xFF;
	}

	AppData->Buff[byte++] = (gpsData.time >> 12) & 0xFF;
	AppData->Buff[byte++] = (gpsData.time >> 4) & 0xFF;
	AppData->Buff[byte] = (gpsData.time << 4) & 0xFF;

	AppData->Buff[byte++] |= (gpsData.satsFix & 0xFF);

	AppData->Buff[byte++] = (gpsData.altitude >> 8) & 0xFF;
	AppData->Buff[byte++] = gpsData.altitude & 0xFF;

	AppData->Buff[byte++] = (gpsData.altitudeSee >> 8) & 0xFF;
	AppData->Buff[byte++] = gpsData.altitudeSee & 0xFF;

	AppData->Buff[byte++] = (gpsData.speed >> 8) & 0xFF;
	AppData->Buff[byte++] = gpsData.speed & 0xFF;

	AppData->Buff[byte++] = (gpsData.speedScale >> 8) & 0xFF;
	AppData->Buff[byte++] = gpsData.speedScale & 0xFF;

	AppData->BuffSize = byte;

	printf("PAYLOAD: latitude: %ld, longitude: %ld, time: %lu nSats: %u\n", gpsData.latitude, gpsData.longitude, gpsData.time, gpsData.satsFix);

	for(uint8_t i = 0; i < byte; i++) {
		printf("%02X ", AppData->Buff[i]);
	}

	printf("\n");

	/* USER CODE END 3 */
}

static void LoraRxData( lora_AppData_t *AppData )
{
	/* USER CODE BEGIN 4 */
	switch (AppData->Port)
	{
	case LORAWAN_APP_PORT:
		if( AppData->BuffSize == 1 )
		{
			AppLedStateOn = AppData->Buff[0] & 0x01;
			if ( AppLedStateOn == RESET )
			{
				printf("LED OFF\n\r");
				LED_Off( LED_BLUE ) ;

			}
			else
			{
				printf("LED ON\n\r");
				LED_On( LED_BLUE ) ;
			}
			//GpioWrite( &Led3, ( ( AppLedStateOn & 0x01 ) != 0 ) ? 0 : 1 );
		}
		break;

	default:
		break;
	}
	/* USER CODE END 4 */
}

#ifdef USE_B_L072Z_LRWAN1
static void OnTimerLedEvent( void ) {
	LED_Off(LED1) ;
}
#endif
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
