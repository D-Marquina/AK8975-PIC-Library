/* 
 * AK8975 Compass Library for PIC18
 * File:   AK8975Compass.h
 * Author: Daniel Marquina
 * 
 * Library for the AK8975 Compass included in IMU MPU9150.
 * This library is based on the AK8975 Device Library for Arduino by Jeff 
 * Rowberg.
 * For information regarding the AK8975 Compass' register values, read the
 * AK8975 Datasheet.
 * Requires I2CdevMod.X.
 * 
 * Created on 30/09/2017
 * 
 * Copyright (c) 2011 Jeff Rowberg
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina
 */

#ifndef AK8975COMPASS_H
#define	AK8975COMPASS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "I2CdevMod.h"

// Default information about AK8975 Compass ====================================
#define AK8975_DEF_ADDR 0x0C 
#define AK8975_ID 0x48 

// Registers of AK8975 Compass =================================================
#define AK8975_WIA 0x00 
#define AK8975_INFO 0x01 
#define AK8975_ST1 0x02 
#define AK8975_HXL 0x03 
#define AK8975_HXH 0x04  
#define AK8975_HYL 0x05  
#define AK8975_HYH 0x06  
#define AK8975_HZL 0x07   
#define AK8975_HZH 0x08
#define AK8975_ST2 0x09 
#define AK8975_CNTL 0x0A 
#define AK8975_RSV 0x0B
#define AK8975_ASTC 0x0C
#define AK8975_TS1 0x0D 
#define AK8975_TS2 0x0E 
#define AK8975_I2CDIS 0x0F
#define AK8975_ASAX 0x10
#define AK8975_ASAY 0x11
#define AK8975_ASAZ 0x12

// Settings of AK8975 Compass ==================================================
// Operation Mode
#define AK9875_POWER_DOWN 0x00
#define AK9875_SINGLE_MEASUREMENT 0x01
#define AK9875_SELF_TEST 0x08
#define AK9875_FUSE_ROM_ACCES 0x0F

// Variables ===================================================================
uint8_t AK8975_Addr;
uint8_t AK8975_Asa[3]; 
int16_t AK8975_rawH[3];

// Functions declarations ======================================================
void AK8975SetAddr( uint8_t Addr );
bit AK8975CheckCom();
bit AK8975ReadAsa();
bit AK8975Init();
bit AK8975ReadDRDY();
bit AK8975ReadRawH();
bit AK8975AdjustH( float* pAdjH );

/* Functions to be implemented but not needed, yet
uint8_t AK8975GetInfo();
bit AK8975ReadDERR();
bit AK8975ReadHOFL();
void AK8975SelfTest( float32* pSTHX, float32* pSTHY, float32* pSTHZ);
void AK8975_disI2C();
*/

#ifdef	__cplusplus
}
#endif

#endif	/* AK8975COMPASS_H */
