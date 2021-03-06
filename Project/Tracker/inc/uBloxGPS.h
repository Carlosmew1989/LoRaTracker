#ifndef __UBLOX_GPS_H__
#define __UBLOX_GPS_H__

#include <stdint.h>
#include "GPSCommon.h"

#define GPS_USART USART1;
#define GPS_USART_CLK_ENABLE() __HAL_RCC_USART1_CLK_ENABLE()
#define GPS_USART_AF GPIO_AF4_USART1

#define GPS_USART_TX_PIN GPIO_PIN_9
#define GPS_USART_TX_PIN_PORT GPIOA

#define GPS_USART_RX_PIN GPIO_PIN_10
#define GPS_USART_RX_PIN_PORT GPIOA

#define GPS_USART_TX_RX_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

#define GPS_DMA_CLK_ENABLE() __HAL_RCC_DMA1_CLK_ENABLE()

#define GPS_USART_TX_DMA_CHANNEL             DMA1_Channel4
#define GPS_USART_RX_DMA_CHANNEL             DMA1_Channel5

#define GPS_USART_TX_RX_DMA_REQUEST             DMA_REQUEST_4

#define GPS_USART_DMA_TX_RX_IRQn             DMA1_Channel4_5_6_7_IRQn

#define GPS_USART_IRQn                      USART1_IRQn

#define GPS_READ_BUF_SIZE 100

extern uint8_t GPSDataReadyFlag;

void GPSInit();

void GPSReadData(GPSData_t *gData);

#endif /* __UBLOX_GPS_H__ */
