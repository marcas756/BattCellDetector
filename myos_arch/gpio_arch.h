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


#ifndef GPIO_ARCH_H_
#define GPIO_ARCH_H_

#include "main.h"

#define GPIO_ARCH_STATE_SET   GPIO_PIN_SET
#define GPIO_ARCH_STATE_RST   GPIO_PIN_RESET

#define GPIO_ARCH_SET(name) HAL_GPIO_WritePin(name##_GPIO_Port, name##_Pin, GPIO_PIN_SET)
#define GPIO_ARCH_RST(name) HAL_GPIO_WritePin(name##_GPIO_Port, name##_Pin, GPIO_PIN_RESET)
#define GPIO_ARCH_TGL(name) HAL_GPIO_TogglePin(name##_GPIO_Port, name##_Pin)
#define GPIO_ARCH_WR(name,value) HAL_GPIO_WritePin(name##_GPIO_Port, name##_Pin, value)
#define GPIO_ARCH_RD(name) HAL_GPIO_ReadPin(name##_GPIO_Port, name##_Pin)

#endif /* GPIO_ARCH_H_ */
