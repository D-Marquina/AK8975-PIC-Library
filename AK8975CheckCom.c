/* 
 * File:   AK8975CheckCom.c
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

/* Check Connection whit AK8975 Compass
 *  Reads AK8975_WIA register, checks status of operation and compares IDs.
 *  @return Status of connection with AK8975 Compass:
 *      - True: if connected (IDs match)
 *      - False: if IDs mismatch or an error ocurred while reading
 */
bit AK8975CheckCom() {

    uint8_t readID;
    bit err = ~I2CdevModReadByte(AK8975_Addr, AK8975_WIA, &readID);
    if(err){
        return false;
    }
    if(readID == AK8975_ID){
        return true;
    }
    else{
        return false;
    }
}

