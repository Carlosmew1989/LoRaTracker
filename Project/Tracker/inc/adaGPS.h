/*
 * adaGPS.h
 *
 *  Created on: 27.01.2018
 *      Author: Carlos
 */

#ifndef TRACKER_INC_ADAGPS_H_
#define TRACKER_INC_ADAGPS_H_

#include "GPSCommon.h"

#define GPS_USART USART1;
#define GPS_USART_CLK_ENABLE() __HAL_RCC_USART1_CLK_ENABLE()
#define GPS_USART_AF GPIO_AF4_USART1

#define GPS_USART_TX_PIN GPIO_PIN_9
#define GPS_USART_TX_PIN_PORT GPIOA

#define GPS_USART_RX_PIN GPIO_PIN_10
#define GPS_USART_RX_PIN_PORT GPIOA

#define GPS_USART_TX_RX_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

#define GPS_USART_IRQn USART1_IRQn

#define SIZE_OF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

extern bool GPSDataReadyFlag;

void GPSInit();

void GPSIoInit();

void GPSReadData(GPSData_t *gpsData);

#endif /* TRACKER_INC_ADAGPS_H_ */
