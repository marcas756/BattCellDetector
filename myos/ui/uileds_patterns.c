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


#include "uileds_patterns.h"

UILEDS_PATTERN_BEGIN(on)
    UILEDS_STATE(UILEDS_STATE_ON,   1)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(off)
    UILEDS_STATE(UILEDS_STATE_OFF,  1)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(fast_flashing)
    UILEDS_STATE(UILEDS_STATE_ON,   10)
    UILEDS_STATE(UILEDS_STATE_OFF,  10)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(medium_flashing)
    UILEDS_STATE(UILEDS_STATE_ON,   20)
    UILEDS_STATE(UILEDS_STATE_OFF,  20)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(slow_flashing)
    UILEDS_STATE(UILEDS_STATE_ON,   40)
    UILEDS_STATE(UILEDS_STATE_OFF,  40)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(single_flash)
    UILEDS_STATE(UILEDS_STATE_ON,   6)
    UILEDS_STATE(UILEDS_STATE_OFF,  94)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(double_flash)
    UILEDS_STATE(UILEDS_STATE_ON,   6)
    UILEDS_STATE(UILEDS_STATE_OFF,  6)
    UILEDS_STATE(UILEDS_STATE_ON,   6)
    UILEDS_STATE(UILEDS_STATE_OFF,  82)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(heart_beat)
    UILEDS_STATE(UILEDS_STATE_ON,   8)
    UILEDS_STATE(UILEDS_STATE_OFF,  6)
    UILEDS_STATE(UILEDS_STATE_ON,   3)
    UILEDS_STATE(UILEDS_STATE_OFF,  83)
UILEDS_PATTERN_END()

UILEDS_PATTERN_BEGIN(triple_flash)
    UILEDS_STATE(UILEDS_STATE_ON,   6)
    UILEDS_STATE(UILEDS_STATE_OFF,  6)
    UILEDS_STATE(UILEDS_STATE_ON,   6)
    UILEDS_STATE(UILEDS_STATE_OFF,  6)
    UILEDS_STATE(UILEDS_STATE_ON,   6)
    UILEDS_STATE(UILEDS_STATE_OFF,  70)
UILEDS_PATTERN_END()


