#ifndef CRC16_H_
#define CRC16_H_
#include <stdint.h>

/**
 * @file crc16.h
 *
 * @author Dr. Maykel Alonso (see https://www.embeddedrelated.com/showcode/295.php)
 * @copyright  Copyright 2013  Dr. Maykel Alonso (see https://www.embeddedrelated.com/showcode/295.php)
 * @license    No license information available
 *
 * @brief Implementation of 16-bit Cyclic Redundancy Check (CRC16).
 *
 * @details
 * Cyclic Redundancy Check (CRC) is an error-detecting code commonly used to detect
 * accidental changes to data in digital networks and storage devices. The 16-bit
 * version, CRC16, is particularly prevalent due to its effective balance between
 * speed and error detection capabilities.
 *
 * Error Detection Properties:
 * - CRC16 can detect all single-bit errors (where only one bit changes in the data block).
 * - It can detect all double-bit errors (two bits change) and all odd number of bit errors.
 * - For larger error patterns, such as burst errors, CRC16 can detect most small error
 *   bursts (the length of the burst is less than 16 bits).
 * - CRC16 is most effective in detecting errors in data blocks that are significantly longer
 *   than 16 bits.
 *
 * Error Correction Capability:
 * - CRC, including CRC16, is primarily designed for error detection, not correction. It can
 *   indicate that a data block contains errors, but it doesn't specify where the error is
 *   located or what the correct value should be.
 * - However, in some cases, CRC can be used in conjunction with other algorithms to correct
 *   certain types of errors, typically in scenarios where the probability of multiple errors
 *   is low.
 *
 * Historical Context:
 * Introduced by W. Wesley Peterson in 1961, CRC has become a standard technique in data
 * transmission and storage for detecting errors. CRC16 is widely adopted across various
 * applications, including communication protocols like Bluetooth and USB, due to its
 * effectiveness in catching common types of errors such as noise in transmission channels.
 *
 * Use Cases:
 * - Ensuring data integrity during transmission over networks or storage on physical media.
 * - Widely used in communication protocols for verifying the integrity of transmitted messages.
 *
 * Key Property:
 * A fundamental property of CRC computation is that the CRC of the data block appended
 * with its own CRC value results in zero. This property is crucial for error detection,
 * as any alteration in the data or the CRC value will result in a non-zero outcome,
 * signaling potential errors.
 *
 *
 * @see crc16_acc, crc16
 *
 * This file was documented in doxygen style format by using ChatGPT 4.
 */

/**
 * @brief Polynomial used for CRC16 in DNP, IEC 870, M-BUS, wM-BUS protocols.
 * @details This macro defines the polynomial 0x3D65 used in the CRC16 calculation
 *          for several communication protocols. Each protocol uses this specific
 *          polynomial for its error-checking purposes, likely due to historical
 *          and standardization reasons in their respective development and implementation.
 *
 *          - DNP (Distributed Network Protocol): A set of communication protocols
 *            used between components in process automation systems.
 *            [ https://en.wikipedia.org/wiki/DNP3 ]
 *
 *          - IEC 870 (Now IEC 60870-5): A standard for telecontrol in electrical
 *            engineering and power system automation.
 *            [ https://en.wikipedia.org/wiki/IEC_60870-5 ]
 *
 *
 *          - M-BUS (Meter-Bus): A European standard for reading gas or electricity
 *            meters.
 *            [ https://en.wikipedia.org/wiki/Meter-Bus ]
 *
 *          - wM-BUS (Wireless M-BUS): The wireless variant of M-BUS used for remote
 *            reading of gas or electricity meters.
 *
 *          These protocols have adopted this polynomial for CRC calculations, possibly
 *          due to its effectiveness in error detection in their specific types of
 *          communication and data transmission.
 */
#define CRC16_DNP       0x3D65

/**
 * @brief Polynomial used for CRC16 in X.25, V.41, HDLC FCS, Bluetooth, etc.
 * @details This macro defines the polynomial 0x1021 which is widely used in CRC16
 *          calculations for various communication standards. The use of this specific
 *          polynomial is based on its historical adoption and proven effectiveness
 *          in error detection for these protocols.
 *
 *          - CCITT: "International Telegraph and Telephone Consultative Committee,"
 *            now known as the ITU-T (International Telecommunication Union -
 *            Telecommunication Standardization Sector). It is a standardization body
 *            responsible for defining various telecommunications standards.
 *            [ https://en.wikipedia.org/wiki/ITU-T ]
 *
 *          - X.25: An ITU-T standard protocol suite for packet-switched data
 *            communication in wide area networks (WANs). X.25 networks were popular
 *            in the 1970s and 1980s.
 *            [ https://en.wikipedia.org/wiki/X.25 ]
 *
 *          - V.41: A standard for error-checking in telecommunication messages,
 *            established by the ITU-T.
 *
 *          - HDLC FCS (High-Level Data Link Control Frame Check Sequence): A
 *            bit-oriented synchronous data link layer protocol developed by the
 *            International Organization for Standardization (ISO). The FCS field
 *            in HDLC frames uses this polynomial for error detection.
 *            [ https://en.wikipedia.org/wiki/High-Level_Data_Link_Control ]
 *            [ https://en.wikipedia.org/wiki/Frame_check_sequence ]
 *
 *          - Bluetooth: A wireless technology standard for exchanging data over
 *            short distances. Bluetooth also uses this polynomial in its data
 *            packets for ensuring data integrity.
 *            [ https://en.wikipedia.org/wiki/Bluetooth ]
 *
 *          The adoption of 0x1021 in these protocols, particularly in those
 *          standardized by the CCITT/ITU-T, highlights its robustness in detecting
 *          errors in a wide range of data communication scenarios.
 */
#define CRC16_CCITT     0x1021

/**
 * @brief Polynomial used for CRC16 in ModBus, USB, Bisync, CRC-16, and CRC-16-ANSI protocols.
 * @details This macro defines the polynomial 0x8005, which is commonly used in CRC16
 *          calculations for various communication and data transmission standards. This
 *          polynomial has been widely adopted due to its effectiveness in error detection.
 *
 *          - ModBus: A communication protocol typically used for transmitting data over
 *            serial lines between electronic devices. It is a de facto standard in
 *            industrial communication.
 *            [ https://en.wikipedia.org/wiki/Modbus ]
 *
 *          - USB (Universal Serial Bus): An industry standard for cables, connectors,
 *            and protocols for connection, communication, and power supply between
 *            computers, peripherals, and other computers.
 *            [ https://en.wikipedia.org/wiki/USB ]
 *
 *          - Bisync (Binary Synchronous Communications): A character-oriented protocol
 *            developed by IBM for synchronous serial communication using teleprinter
 *            circuits or telephone lines.
 *            [ https://en.wikipedia.org/wiki/Binary_Synchronous_Communications ]
 *
 *
 *          - CRC-16: A widely used variant of CRC (Cyclic Redundancy Check) algorithms,
 *            particularly in telecommunications and storage, with a 16-bit hash value.

 *
 *          - CRC-16-ANSI: A version of the CRC-16 algorithm, standardized by the American
 *            National Standards Institute. It is used in various applications similar to
 *            the IBM version.

 *
 *          This polynomial is particularly popular in industrial and telecommunication
 *          applications, reflecting its reliability in a wide range of environments and
 *          data communication protocols.
 */
#define CRC16_IBM       0x8005

/**
 * @brief Polynomial used for CRC16 in SCSI DIF.
 * @details This macro defines the polynomial 0x8BB7, which is specifically used in
 *          the CRC16 calculation for SCSI DIF (Data Integrity Field). The selection
 *          of this polynomial is aligned with its application in ensuring data integrity
 *          within the SCSI (Small Computer System Interface) standard, particularly
 *          in the context of storage devices.
 *
 *          - SCSI DIF (Small Computer System Interface Data Integrity Field):
 *            An extension to the traditional SCSI standard, DIF adds an additional
 *            layer of data protection by incorporating a field that stores CRC
 *            values. This CRC is computed for each block of data using the 0x8BB7
 *            polynomial, providing a mechanism to detect and prevent data corruption
 *            during storage and transmission. The use of CRC16 with this particular
 *            polynomial is critical for maintaining data integrity in high-reliability
 *            storage systems, where data corruption can have significant consequences.
 *            [ https://en.wikipedia.org/wiki/SCSI ]
 *            [ https://en.wikipedia.org/wiki/Data_Integrity_Field ]
 *
 *
 *          The adoption of 0x8BB7 in SCSI DIF reflects the need for a robust error-checking
 *          mechanism in storage systems, providing a high level of protection against data
 *          corruption and ensuring data integrity across storage operations.
 */
#define CRC16_T10_DIF   0x8BB7

/**
 * @brief Polynomial used for CRC16 in DECT (Cordless Telephones).
 * @details This macro defines the polynomial 0x0589, which is used in the CRC16
 *          calculation for DECT standard compliance. This specific polynomial is
 *          chosen for its effectiveness in error detection in the communication
 *          protocols of cordless telephones.
 *
 *          - DECT (Digital Enhanced Cordless Telecommunications):
 *            A standard primarily used for creating cordless telephone systems.
 *            It is a digital communication standard, which ensures that cordless
 *            phone communications are secure, high-quality, and interference-free.
 *            The CRC16 polynomial 0x0589 plays a crucial role in the DECT standard
 *            by providing a reliable method for error checking in the data
 *            transmission process. This level of error detection is essential for
 *            maintaining the integrity and clarity of voice data over wireless
 *            communication channels.
 *            [ https://en.wikipedia.org/wiki/Digital_enhanced_cordless_telecommunications ]
 *
 *          The use of this polynomial in DECT systems underscores the importance
 *          of robust error detection mechanisms in wireless communication,
 *          particularly in scenarios where clarity and security of voice
 *          communication are paramount.
 */
#define CRC16_DECT      0x0589

/**
 * @brief Polynomial used for CRC16 in ACARS Applications.
 * @details This macro defines the polynomial 0xA02B, which is utilized in the CRC16
 *          calculations for ACARS applications. This polynomial is specifically selected
 *          for its effectiveness in detecting errors within the aviation communication protocols.
 *
 *          - ACARS (Aircraft Communications Addressing and Reporting System):
 *            A digital datalink system for transmission of short, relatively simple messages
 *            between aircraft and ground stations via airband radio or satellite. ACARS is used
 *            for a wide range of purposes, including conveying operational control messages
 *            between aircraft and air traffic control, position reporting, and the automatic
 *            sending of in-flight fault reporting to maintenance bases. The use of CRC16
 *            with the polynomial 0xA02B in ACARS is critical for ensuring the accuracy and
 *            reliability of these communications, which are vital for aircraft operation
 *            and safety.
 *            [ https://en.wikipedia.org/wiki/ACARS ]
 *
 *          The adoption of this polynomial in ACARS reflects the stringent requirements
 *          for error detection in aviation communication systems, where data integrity and
 *          accuracy are crucial for flight safety and operational efficiency.
 */
#define CRC16_ARINC     0xA02B

/**
 * @brief Accumulates a CRC16 checksum for a single byte.
 * @details This function computes the CRC16 checksum of a single byte, using a
 *          provided seed value and polynomial. It's typically used in a loop to
 *          calculate the CRC16 checksum of a data stream byte by byte.
 *
 * @param seed The initial or previously accumulated CRC16 value.
 * @param polynom The polynomial used for the CRC calculation. This value determines
 *                the specific CRC16 algorithm being implemented.
 * @param byte The byte of data for which the CRC16 checksum is to be computed.
 *
 * @return The updated CRC16 checksum after processing the given byte.
 *
 * Example Usage:
 *      uint16_t seed = 0xFFFF; // Initial CRC value
 *      uint16_t polynom = CRC16_CCITT; // CRC16 polynomial
 *      uint8_t data[] = {0x01, 0x02, 0x03, 0x04};
 *      size_t data_len = sizeof(data) / sizeof(data[0]);
 *
 *      for (size_t i = 0; i < data_len; ++i) {
 *          seed = crc16_acc(seed, polynom, data[i]);
 *      }
 *
 *      // 'seed' now holds the final CRC16 checksum of the data array
 *
 * @note This function processes one byte at a time and can be called iteratively
 *       to calculate the CRC of a sequence of bytes.
 */
uint16_t crc16_acc(uint16_t seed, uint16_t polynom, uint8_t byte);

 /**
  * @brief Computes the CRC16 checksum for a data array.
  * @details This function calculates the CRC16 checksum using a specified polynomial
  *          and an initial seed value. It processes each byte in the provided data
  *          array, accumulating the CRC16 checksum. This function is typically used
  *          in communication protocols to ensure data integrity.
  *
  * @param seed The initial CRC value, typically 0xFFFF or another specified seed.
  * @param polynom The polynomial used for the CRC calculation. Different standards
  *                may use different polynomials.
  * @param data Pointer to the data array over which the CRC16 is to be computed.
  * @param size The size of the data array in bytes.
  *
  * @return The CRC16 checksum of the data array.
  *
  * Example Usage:
  *      uint16_t polynom = CRC16_CCITT; // Polynomial for CRC16-CCITT
  *      uint8_t data[] = {0x01, 0x02, 0x03, 0x04}; // Example data
  *      size_t size = sizeof(data);
  *      uint16_t seed = 0xFFFF; // Initial CRC value
  *      uint16_t crc = crc16(seed, polynom, data, size);
  *
  * @note This function uses the crc16_acc function internally to process each byte.
  */
uint16_t crc16(uint16_t seed, uint16_t polynom, uint8_t *data, size_t size);



#endif /* CRC16_H_ */
