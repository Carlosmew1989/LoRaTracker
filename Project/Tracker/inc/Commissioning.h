/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2015 Semtech

Description: End device commissioning parameters

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
 /******************************************************************************
  * @file    commissioning.h
  * @author  MCD Application Team
  * @version V1.1.2
  * @date    08-September-2017
  * @brief   End device commissioning parameters
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LORA_COMMISSIONING_H__
#define __LORA_COMMISSIONING_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
/*!
 * When set to 1 the application uses the Over-the-Air activation procedure
 * When set to 0 the application uses the Personalization activation procedure
 */
#define OVER_THE_AIR_ACTIVATION                     0

/*!
 * Indicates if the end-device is to be connected to a private or public network
 */
#define LORAWAN_PUBLIC_NETWORK                      false

/*!
 * When set to 1 DevEui is LORAWAN_DEVICE_EUI
 * When set to 0 DevEui is automatically generated by calling
 *         BoardGetUniqueId function
 */
#define STATIC_DEVICE_EUI                     1

/*!
 * Mote device IEEE EUI (big endian)
 *
 * \remark see STATIC_DEVICE_EUI comments
 *
 * B-L072Z-LRWAN1-Board-ABP: 32 19 92 07 12 8F 20 D6
 * TTN bl072zlrwan-1: 00 21 AC C5 92 75 69 A7
 * TTN bl072zlrwan-2: 00 C0 24 77 A0 AB D8 87
 */
//#define LORAWAN_DEVICE_EUI                          { 0x32, 0x19, 0x92, 0x07, 0x12, 0x8F, 0x20, 0xD6 }
#define LORAWAN_DEVICE_EUI                          { 0x00, 0x21, 0xAC, 0xC5, 0x92, 0x75, 0x69, 0xA7 }
//#define LORAWAN_DEVICE_EUI                          { 0x00, 0xC0, 0x24, 0x77, 0xA0, 0xAB, 0xD8, 0x87 }

/*!
 * Application IEEE EUI (big endian)
 *
 * TTN lorawangpstracker: 70 B3 D5 7E D0 00 94 29
 */
#define LORAWAN_APPLICATION_EUI                     { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x00, 0x94, 0x29 }

/*!
 * AES encryption/decryption cipher application key
 *
 * TTN bl072zlrwan-1: A4 E0 1E 14 B9 67 32 28 AF D5 65 16 2F 08 5C B1
 * TTN bl072zlrwan-2: F4 9D D0 74 0C 54 28 AA 54 64 82 B6 B0 45 46 91
 */
//#define LORAWAN_APPLICATION_KEY                     { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C }
//#define LORAWAN_APPLICATION_KEY                     { 0xA4, 0xE0, 0x1E, 0x14, 0xB9, 0x67, 0x32, 0x28, 0xAF, 0xD5, 0x65, 0x16, 0x2F, 0x08, 0x5C, 0xB1 }
#define LORAWAN_APPLICATION_KEY                     { 0xF4, 0x9D, 0xD0, 0x74, 0x0C, 0x54, 0x28, 0xAA, 0x54, 0x64, 0x82, 0xB6, 0xB0, 0x45, 0x46, 0x91 }

#if( OVER_THE_AIR_ACTIVATION == 0 )

/*!
 * Current network ID
 */
#define LORAWAN_NETWORK_ID                          ( uint32_t )0

/*!
 * When set to 1 DevAdd is LORAWAN_DEVICE_ADDRESS
 * When set to 0 DevAdd is automatically generated using
 *         a pseudo random generator seeded with a value derived from
 *         BoardUniqueId value
 */
#define STATIC_DEVICE_ADDRESS                     1
/*!
 * Device address on the network (big endian)
 *
 * \remark see STATIC_DEVICE_ADDRESS comments
 *
 * B-L072Z-LRWAN1-Board-ABP: 73 C2 C9 48
 *
 * ABP
 * TTN bl072zlrwan-1: 26 01 1D 9B
 * TTN bl072zlrwan-2: 26 01 1C 23
 */
//#define LORAWAN_DEVICE_ADDRESS                      ( uint32_t )0x73C2C948
#define LORAWAN_DEVICE_ADDRESS                      ( uint32_t )0x26011D9B
//#define LORAWAN_DEVICE_ADDRESS                      ( uint32_t )0x26011C23

/*!
 * AES encryption/decryption cipher network session key
 *
 * B-L072Z-LRWAN1-Board-ABP: EC 76 A8 E9 95 DE F3 76 13 C2 F8 62 84 78 05 AA
 *
 * TTN bl072zlrwan-1: 53 E0 C9 B6 5F 20 F1 26 86 9E B0 DD 60 0E 99 00
 * TTN bl072zlrwan-2: 74 F9 58 FF 53 7F E1 82 1B B5 CD C8 86 73 F3 CF
 */
//#define LORAWAN_NWKSKEY                             { 0xEC, 0x76, 0xA8, 0xE9, 0x95, 0xDE, 0xF3, 0x76, 0x13, 0xC2, 0xF8, 0x62, 0x84, 0x78, 0x05, 0xAA }
#define LORAWAN_NWKSKEY                              { 0x53, 0xE0, 0xC9, 0xB6, 0x5F, 0x20, 0xF1, 0x26, 0x86, 0x9E, 0xB0, 0xDD, 0x60, 0x0E, 0x99, 0x00 }
//#define LORAWAN_NWKSKEY                              { 0x74, 0xF9, 0x58, 0xFF, 0x53, 0x7F, 0xE1, 0x82, 0x1B, 0xB5, 0xCD, 0xC8, 0x86, 0x73, 0xF3, 0xCF }

/*!
 * AES encryption/decryption cipher application session key
 *
 * B-L072Z-LRWAN1-Board-ABP: 4B E9 68 26 29 7D 3E C4 81 16 42 58 77 B5 AB FD
 *
 * TTN bl072zlrwan-1: 50 D0 53 30 82 32 11 FE A2 80 A0 16 2C 55 B8 C7
 * TTN bl072zlrwan-2: A5 8B 6A 26 77 6B F7 12 4B 66 62 F3 F4 94 23 38
 */
//#define LORAWAN_APPSKEY                             { 0x4B, 0xE9, 0x68, 0x26, 0x29, 0x7D, 0x3E, 0xC4, 0x81, 0x16, 0x42, 0x58, 0x77, 0xB5, 0xAB, 0xFD }
#define LORAWAN_APPSKEY                             { 0x50, 0xD0, 0x53, 0x30, 0x82, 0x32, 0x11, 0xFE, 0xA2, 0x80, 0xA0, 0x16, 0x2C, 0x55, 0xB8, 0xC7 }
//#define LORAWAN_APPSKEY                             { 0xA5, 0x8B, 0x6A, 0x26, 0x77, 0x6B, 0xF7, 0x12, 0x4B, 0x66, 0x62, 0xF3, 0xF4, 0x94, 0x23, 0x38 }

#endif /* OVER_THE_AIR_ACTIVATION == 0 */


#ifdef __cplusplus
}
#endif

#endif /* __LORA_COMMISSIONING_H__ */
