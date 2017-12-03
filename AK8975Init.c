/* 
 * File:   AK8975Init.c
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

/* Initialize AK8975 Compass.
 *  Sets the default address, checks communication and stores the sensitivity 
 *  adjustment values.
 *  @return State of operations:
 *      - True: if every ACK was received
 *      - False: if any ACK was missing
 */
bit AK8975Init() {
    
    bit statOp = true;
    AK8975SetAddr(AK8975_DEF_ADDR);
    statOp &= AK8975CheckCom();
    statOp &= AK8975ReadAsa();
    return statOp;
}

