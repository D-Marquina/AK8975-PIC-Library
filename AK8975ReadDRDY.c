/* 
 * File:   AK8975ReadDRDY.c
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

/* Read DRDY bit from AK8975 Compass
 *  Reads DRDY bit value.
 *  @return drdySt: Status of DRDY bit
 *      - True: if data is ready
 *      - False: if data is not ready or an error ocurred
 */
bit AK8975ReadDRDY() {

    uint8_t drdySt = 0;
    I2CdevModReadBit( AK8975_Addr, AK8975_ST1, 0, &drdySt );
    if(drdySt == 0x01){
        return true;
    }
    else{
        return false;
    }
}

