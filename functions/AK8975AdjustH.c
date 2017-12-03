/* 
 * File:   AK8975AdjustH.c
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

/* Adjust data from AK8975 Compass
 *  Reads data, adjusts, converts to uT and sends through pointers.
 *  @param pAdjH: pointer to array where adjusted HX, HY and HZ will be stored.
 *  @return: statOp: Status of operation
 *      - True: if every ACK was received
 *      - False: if any ACK was not received
 */
bit AK8975AdjustH( float* pAdjH ) {

    bit statOp = true;
    statOp &= AK8975ReadRawH();
    pAdjH[0] = ((float)AK8975_rawH[0])*(((float)AK8975_Asa[0])+128)*3/2560;
    pAdjH[1] = ((float)AK8975_rawH[1])*(((float)AK8975_Asa[1])+128)*3/2560;
    pAdjH[2] = ((float)AK8975_rawH[2])*(((float)AK8975_Asa[2])+128)*3/2560;
    return statOp;
}

