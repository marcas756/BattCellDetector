#ifndef CRC16_H_
#define CRC16_H_
#include <stdint.h>

// https://gist.github.com/hemonserrat/d6b1a9ceff6a3a4d01fc0c706a4be325

#define CRC16_DNP       0x3D65      // DNP, IEC 870, M-BUS, wM-BUS, ...
#define CRC16_CCITT     0x1021      // X.25, V.41, HDLC FCS, Bluetooth, ...
#define CRC16_IBM       0x8005      // ModBus, USB, Bisync, CRC-16, CRC-16-ANSI, ...
#define CRC16_T10_DIF   0x8BB7      // SCSI DIF
#define CRC16_DECT      0x0589      // Cordeless Telephones
#define CRC16_ARINC     0xA02B      // ACARS Aplications

uint16_t crc16_acc(uint16_t seed, uint16_t polynom, uint8_t byte);

#endif /* CRC16_H_ */
