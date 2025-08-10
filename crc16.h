/*
   File: crc16.h

   	  Functions to calculate CRC16
*/

#ifndef _P1_CRC16_H_
#define _P1_CRC16_H_

#include <inttypes.h>

uint16_t crc16_ccitt (const uint8_t *data, unsigned int length);
uint16_t crc16 (const uint8_t *data, unsigned int length);

#endif _P1_CRC16_H_
