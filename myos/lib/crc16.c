#include "crc16.h"

// https://gist.github.com/hemonserrat/d6b1a9ceff6a3a4d01fc0c706a4be325

uint16_t crc16_acc(uint16_t seed, uint16_t polynom, uint8_t byte)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {

        if (((seed & 0x8000) >> 8) ^ (seed & 0x80)){
            seed = (seed << 1)  ^ polynom;
        }else{
            seed = (seed << 1);
        }

        byte <<= 1;
    }

    return seed;
}

