/* 
 * File:   AK8975SerAddr.c
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

/* Set AK8975 Compass Address
 *  Sets the address. Check possibles addresses in datasheet.
 *  @param Addr: Address
 */
void AK8975SetAddr( uint8_t Addr ) {

    AK8975_Addr = Addr;
}

