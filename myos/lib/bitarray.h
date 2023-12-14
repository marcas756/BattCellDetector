/*
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
 \file	    bitarray.h

 \brief

 \details
 */
#ifndef BITARRAY_H_
#define BITARRAY_H_
#include <stdint.h> /* uint8_t */
#include <string.h> /* memset */


#define BITARRAY_RESET_STATE    0
#define BITARRAY_SET_STATE      1

typedef uint8_t bitarray_t;


/*!
    \brief      Defines an bit array

    \param      name        Name of the bit array
    \param      size        Minimum number of bits required
*/
#define BITARRAY(name,size) \
    bitarray_t name##_bitarray[((size)+7)>>3]

#define BITARRAY_INIT(name) \
    memset(name##_bitarray,0x00,sizeof(name##_bitarray))




/*!
    \brief      Size of array in bits
    \details    Returns the size of a bit array in bits.
                The size is expressed as a multiple of 8.
    \param      name        Name of the bit array

*/
#define BITARRAY_SIZE(name) \
    ((sizeof(name##_bitarray)/sizeof(name##_bitarray[0]))<<3)
/*!
    \brief      Get a specific bit

    \param      name        Name of the bit array
    \param      bit         Specific bit index

    \return     Value of the specific bit. Either 0 or 1.
*/
#define BITARRAY_GET(name,bit) \
    ((unsigned)((name##_bitarray[((unsigned)(bit))>>3] & ((1<<(((unsigned)(bit))&0x07)))) > 0))


/*!
    \brief      Set a specific bit to 1

    \param      name        Name of the bit array
    \param      bit         Specific bit index


*/
#define BITARRAY_SET(name,bit) \
    name##_bitarray[((unsigned)(bit))>>3] |= (1<<(((unsigned)(bit))&0x07))

/*!
    \brief      Reset a specific bit to 0

    \param      name        Name of the bit array
    \param      bit         Specific bit index
*/
#define BITARRAY_RESET(name,bit) \
    name##_bitarray[((unsigned)(bit))>>3] &= ~(1<<(((unsigned)(bit))&0x07))

/*!
    \brief      Toggle a specific bit

    \param      name        Name of the bit array
    \param      bit         Specific bit index
*/
#define BITARRAY_TOGGLE(name,bit) \
     name##_bitarray[((unsigned)(bit))>>3] ^= (1<<(((unsigned)(bit))&0x07))

/*!
    \brief      Toggle a specific bit

    \param      name        Name of the bit array
    \param      bit         Specific bit index
*/
#define BITARRAY_SET_VALUE(name,bit,value) \
    do{if((value) == 0){BITARRAY_RESET(name,bit);}else{BITARRAY_SET(name,bit);}}while(0)


#endif /* BITARRAY_H_ */
