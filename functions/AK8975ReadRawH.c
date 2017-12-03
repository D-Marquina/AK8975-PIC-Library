/* 
 * File:   AK8975ReadRawH.c
 * Author: Daniel Marquina
 *
 * Created on 30/09/2017
 * 
 * Copyright (c) 2011 Jeff Rowberg
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina
 */

#include "AK8975Compass.h"

/* Read Raw measurement data from AK8975 Compass
 *  Activates single-measurement mode, waits for DRDY to be set, reads data 
 *  registers and stores the values (Little Endian).
 *  Range of values: -4096(0xF000) to +4095(0x0FFF).
 *  @return: statOp: Status of operation
 *      - True: if every ACK was received
 *      - False: if any ACK was not received
 */
bit AK8975ReadRawH() {

    uint8_t buffer[6];
    bit statOp = true;
    statOp &= I2CdevModWriteBits(AK8975_Addr, AK8975_CNTL, 3, 4, AK9875_SINGLE_MEASUREMENT);
    while(!AK8975ReadDRDY()){
    }
    statOp &= I2CdevModReadBytes(AK8975_Addr, AK8975_HXL, 6, buffer);
    AK8975_rawH[0] = (((int16_t)buffer[1]) << 8) | buffer[0];
    AK8975_rawH[1] = (((int16_t)buffer[3]) << 8) | buffer[2];
    AK8975_rawH[2] = (((int16_t)buffer[5]) << 8) | buffer[4];
    return statOp;
}

