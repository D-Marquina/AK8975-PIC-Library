/* 
 * File:   AK8975ReadAsa.c
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

/* Read Asa values from AK8975 Compass
 *  Sets operating mode as Fuse ROM access, reads ASAx registers, stores data in 
 *  AK8975_Asa[] and sets operating mode as Power-down.
 *  @return statOp: Status of reading
 *      - True: if every ACK was received
 *      - False: if any ACK was missing
 */
bit AK8975ReadAsa() {

    bit statOp = true;
    statOp &= I2CdevModWriteBits(AK8975_Addr, AK8975_CNTL, 3, 4, AK9875_FUSE_ROM_ACCES);  
    statOp &= I2CdevModReadBytes(AK8975_Addr, AK8975_ASAX, 3, AK8975_Asa);   
    statOp &= I2CdevModWriteBits(AK8975_Addr, AK8975_CNTL, 3, 4, AK9875_POWER_DOWN); 
    return statOp;
}

