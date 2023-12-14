/*! \copyright
 
   https://opensource.org/license/mit/

   Copyright 2013-2023 Marco Bacchi <marco@bacchi.at>
   
   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without
   restriction, including without limitation the rights to use,
   copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following
   conditions:
   
   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
   OTHER DEALINGS IN THE SOFTWARE.
*/


/*!
    \file       bits.h

    \brief      Provides preprocessor macros for bit manipulations


    \details    Bit field

                A bit field is termed an unsigned integer in which single bits or
                group of bits are stringed together. It represents a kind of compound
                data type on bit level, in contrast to primitive data types, where the
                value is build by interpreting all positions of the primitive data type together.

                A bit field is always embedded in the data type of the binary number (in contrast to bit arrays).


                Bit mask

                Accessing a single bit, either in reading or writing manner,
                is supported by hardware in a similar way like accessing a
                byte or word - it will do with only one command for most machines.

                But support through compiler is often similar to an access on several
                bits, where a bit group has to be "removed" from the variable word before
                comparison or manipulation. This is done by using a a so called bit mask
                and some elementary boolean bit operations.

                Bit masks are called bit fields that do not represent any information themselves,
                but are used to read out or manipulate bit fields.


                Source: https://de.wikipedia.org/wiki/Bitfeld
                Source: https://de.wikipedia.org/wiki/Bitkette
*/
#ifndef BITS_H_
#define BITS_H_

/**
 * @brief Reads out specific bits from a bit field using a bit mask.
 * @details This macro allows for extracting specific bits from a bit field by performing
 *          a logical AND operation with a bit mask. The bit mask should have bits set
 *          (1s) at the positions you want to read and cleared (0s) elsewhere. When the
 *          bit field is AND-ed with this mask, the resulting value contains the bits
 *          from the original bit field that align with the 1s in the mask, with all
 *          other bits set to 0.
 *
 *          This operation is commonly used to isolate a subset of bits within a larger
 *          bit field for examination or further processing.
 *
 * Example Usage:
 *      1-Bit:
 *          01001011 (bit field)
 *      AND 00001000 (bit mask)
 *      ------------
 *          00001000 (result - Bit extracted)
 *
 *      0-Bit:
 *          01001011 (bit field)
 *      AND 00000100 (bit mask)
 *      ------------
 *          00000000 (result - Bit not present)
 *
 * @param x The bit field from which to extract bits.
 * @param m The bit mask specifying which bits to extract.
 * @return The result of the bit field AND-ed with the bit mask.
 */
#define BITS(x,m)           ((x)&(m))

/**
 * @brief Toggles all bits of an integer.
 * @details This macro inverts all bits of the given integer. Each bit that is 0
 *          becomes 1, and each bit that is 1 becomes 0. This is achieved using the
 *          bitwise NOT operation. The inversion of bits is a common operation in
 *          scenarios where you need to flip the bit pattern, for example, when
 *          implementing bitwise algorithms or performing certain kinds of data
 *          transformations.
 *
 * Example Usage:
 *      Original:
 *          01001011 (Original bit pattern of integer)
 *      Invert:
 *          ~01001011
 *      ------------
 *          10110100 (Inverted bit pattern)
 *
 * @param x The integer whose bits are to be toggled.
 * @return The result of inverting all bits of the given integer.
 */
#define BITS_INVERT(x)      (~x)

/**
 * @brief Tests if all bits defined by a bit mask are set in the bit field.
 * @details This macro checks whether all the bits specified in the bit mask are set
 *          (i.e., are 1) in the given bit field. It first performs a logical AND
 *          operation between the bit field and the bit mask, then compares the result
 *          to the bit mask. If the comparison is equal, it means all the bits in the
 *          bit field corresponding to the set bits in the mask are also set.
 *
 *          This operation is useful for checking the state of multiple bits at once
 *          in a bit field, such as in flag checking or feature enabling scenarios.
 *
 * Example Usage:
 *      Check if specific bits are set:
 *          Bit field: 01101101
 *          Bit mask:  00001101
 *      Test:
 *          (01101101 & 00001101) == 00001101
 *      ------------
 *          Result is true (all specified bits are set)
 *
 * @param x The bit field to test.
 * @param m The bit mask defining which bits to check.
 * @return True if all bits defined by the bit mask are set in the bit field, false otherwise.
 */
#define BITS_TEST(x,m)      (((x)&(m))==(m)))

/*!
     \brief     Set bits defined by bit mask to logical 1 in bit field
     \details   To set one or more specific bits of a bit field, it is logically
                OR-ed with a bit mask defining the bits to be set.

                Example

                Set bits to  „1“:

                    01001011 bit field
                OR  00000100 bit mask
                -------------
                =   01001111 result

*/
#define BITS_SET(x,m)       ((x)|=(m))

/*!
    \brief      Set bits defined by bit mask to logical 0 in bit field
    \details    To clear one or more specific bits of a bit field, it is logically
                NAND-ed with a bit mask defining the bits to be cleared.

                Set bits to „0“:

                NOT 00001000 bit mask
                -------------
                =   11110111 inverted bit mask
                AND 01001011 bit field
                -------------
                =   01000011 result
*/
#define BITS_CLEAR(x,m)     ((x)&=~(m))

/*!
    \brief      Toggle bits in bit field as defined by bit mask.
    \details    To toggle one or more specific bits of a bit field, it is logically
                XOR-ed with a bit mask defining the bits to be toggled.

                    01001011 bit field
                XOR 00000110 bit mask
                -------------
                =   01001101 result
*/
#define BITS_TOGGLE(x,m)    ((x)^=(m))

#endif /* BITS_H_ */
