#include "crc16.h"


uint16_t crc16_acc(uint16_t seed, uint16_t polynom, uint8_t byte)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {

        if (((seed & 0x8000) >> 8) ^ (byte & 0x80)){
            seed = (seed << 1)  ^ polynom;
        }else{
            seed = (seed << 1);
        }

        byte <<= 1;
    }

    return seed;
}

uint16_t crc16(uint16_t seed, uint16_t polynom, uint8_t *data, size_t size)
{

    while (size--)
    {
        seed = crc16_acc(seed, polynom, *data++);
    }

    return seed;
}
