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
	\file	buffer.h

    \brief

    \details
*/

#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdint.h>
#include <stddef.h>



/*!
    Declares a buffer type. The argumnents are \a name for a unique identification
    of the buffer type, the \a type of the items and the number of items of \a type
    the buffer can hold (\a size).
*/
#define BUFFER_TYPEDEF(name,type,size)  \
    typedef struct {                    \
            size_t count;               \
            type items [size];          \
    } name##_buffer_t


/*!
     Defines a buffer of type \a name. Can also be combined with different storage classifiers.
    (static, extern, volatile ...)
*/
#define BUFFER_T(name) \
    name##_buffer_t


/*!
    Returns a pointer to the buffer items.
    Type of returned pointer is of buffer item type.
*/
#define BUFFER_ITEMS(buffer) \
    ((buffer).items)

/*!
    Returns an pointer to the buffer items.
    Type of pointer is void.
*/
#define BUFFER_RAW(buffer) \
	((uint8_t*)BUFFER_ITEMS(buffer))

/*!
    Returns the size of the buffer in bytes.
*/
#define BUFFER_SIZEOF(buffer) \
    (sizeof(BUFFER_ITEMS(buffer)))


/*!
     Returns the maximum number of items the buffer can hold.
*/
#define BUFFER_SIZE(buffer) \
    (BUFFER_SIZEOF(buffer)/sizeof(BUFFER_ITEMS(buffer)[0]))

/*!
    Returns the current number of items used in the buffer.
*/
#define BUFFER_COUNT(buffer) \
    ((buffer).count)

/*!
    Initializes the buffer.
*/
#define BUFFER_INIT(buffer) \
    do{BUFFER_COUNT(buffer)=0;}while(0)


/*!
    Checks if no further buffer items are available.
    Returns 1 if buffer is full, otherwise 0.
*/
#define BUFFER_FULL(buffer) \
    (BUFFER_COUNT(buffer)>=BUFFER_SIZE(buffer))

/*!
    Checks if the buffer has no items stored.
    Returns 1 if buffer is empty, otherwise 0.
*/
#define BUFFER_EMPTY(buffer) \
    (!BUFFER_COUNT(buffer))
/*!
    Moves to next free item in the buffer.
    It does not check for buffer overflow.
    In case of buffer overflow the behaviour is undefined.
    Use BUFFER_FULL to check if buffer is full before using this macro.
*/
#define BUFFER_NEXT(buffer) \
    (++BUFFER_COUNT(buffer))

/*!
    Returns the current free item by value.
*/
#define BUFFER_VAL(buffer) \
    (BUFFER_ITEMS(buffer)[BUFFER_COUNT(buffer)])

/*!
    Returns a pointer to the current free item.
*/
#define BUFFER_PTR(buffer) \
    (&BUFFER_VAL(buffer))

/*!
    Append an item to the buffer by value.
    Automatically increases the buffer count.
    It does not check for buffer overflow.
    In case of buffer overflow the behaviour is undefined.
    Use BUFFER_FULL to check if buffer is full before using this macro.
*/
#define BUFFER_APPEND(buffer,item) \
	do{BUFFER_VAL(buffer) = item; BUFFER_NEXT(buffer);}while(0)


#endif /* BUFFER_H_ */
