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


#ifndef UILEDS_H_
#define UILEDS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


#define UILEDS_STATE_OFF    0
#define UILEDS_STATE_ON     1

#define UILEDS_INV          1
#define UILEDS_ORIG         0

typedef void (*uileds_set_t) (bool);

typedef struct {
    unsigned lstate      :1;
    unsigned duration   :7;
} uileds_state_t;

typedef struct uileds_t uileds_t;

struct uileds_t{
    uileds_set_t set_led;
    uileds_state_t *pattern;
    unsigned pstate     :7;
    unsigned inverted   :1;
    unsigned timer      :8;
};

extern const uileds_t* const uileds_all_leds [];

#define UILEDS_PATTERN(name,size) \
      uileds_state_t uileds_pattern_##name [size]


#define UILEDS_PATTERN_BEGIN(name) \
        const uileds_state_t uileds_pattern_##name [] = {

#define EXTERN_UILEDS_PATTERN(name) \
        extern const uileds_state_t uileds_pattern_##name []

#define UILEDS_STATE(state,duration) \
        {state,duration},

#define UILEDS_PATTERN_END() {0,0} };

#define UILEDS_LED(name) \
        void uileds_set_##name(bool state); \
        uileds_t name = {uileds_set_##name}; \
        void uileds_set_##name(bool state)

#define EXTERN_UILEDS_LED(name) \
        extern uileds_t name

#define UILEDS_SET_PATTERN(led_name,pattern_name,invert) \
        uileds_set_pattern(&led_name,(uileds_state_t*)&uileds_pattern_##pattern_name,invert)

#define UILEDS_LEDS(...) \
    const uileds_t* const uileds_all_leds [] = { __VA_ARGS__ }; \
    const unsigned uileds_count = (sizeof(uileds_all_leds)/sizeof(*uileds_all_leds));

#define UILEDS_COUNT (uileds_count)

#define UILEDS_SYNC(which,with,inverted) uileds_sync (&which,&with,inverted)

#define ULEDS_DISABLE_LED(led_name) do { led_name.pattern = NULL; led_name.set_led(UILEDS_STATE_OFF);}while(0)

void uileds_set_pattern (uileds_t* led, uileds_state_t* pattern, bool inverted);
void uileds_handler(void);
extern const unsigned uileds_count;
void uileds_sync (uileds_t* which, uileds_t* with, bool inverted);

#endif /* UILEDS_H_ */
