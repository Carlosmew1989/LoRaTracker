/*
 * GPSCommon.h
 *
 *  Created on: 27.01.2018
 *      Author: Carlos
 */

#ifndef TRACKER_INC_GPSCOMMON_H_
#define TRACKER_INC_GPSCOMMON_H_

#include <stdint.h>

typedef struct GPSDdata {
	uint32_t time;
	uint32_t date;
	uint8_t fixQuality;
	int32_t latitude;
	int32_t longitude;
	uint8_t satsFix;
	uint8_t satsVis;
	int16_t speed;
	uint16_t speedScale;
	int16_t altitude;
	int16_t altitudeSee;
	uint16_t hdop;
	uint16_t pdop;
	uint16_t vdop;
}GPSData_t;

#endif /* TRACKER_INC_GPSCOMMON_H_ */
