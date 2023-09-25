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


#ifndef UIBUTTONS_H_
#define UIBUTTONS_H_

#include <stdbool.h>
#include <stdint.h>
#include "uibuttons_conf.h"



#define UIBUTTONS_STATE_RELEASED            0
#define UIBUTTONS_STATE_PRESSED             1
#define UIBUTTONS_STATE_RELEASED_DEBOUNCE   2
#define UIBUTTONS_STATE_PRESSED_DEBOUNCE    3

#define UIBUTTONS_EVENT_BASE        0

enum {
    UIBUTTONS_EVENT_RISING_EDGE = UIBUTTONS_EVENT_BASE,
    UIBUTTONS_EVENT_FALLING_EDGE,
    UIBUTTONS_EVENT_SHORT_PRESS,
    UIBUTTONS_EVENT_LONG_PRESS,
    UIBUTTONS_EVENT_LONGER_PRESS,
    UIBUTTONS_EVENT_LONGEST_PRESS,
    UIBUTTONS_EVENT_REPEAT_PRESS,
    UIBUTTONS_EVENT_SINGLE_CLICK,
    UIBUTTONS_EVENT_DOUBLE_CLICK,
    UIBUTTONS_EVENT_TRIPLE_CLICK,
};


typedef bool (*uibuttons_get_t) ();

typedef struct {
  uibuttons_get_t get;
  uint8_t prev_state;
#if UIBUTTONS_ENABLE_LONG_PRESS || UIBUTTONS_ENABLE_DEBOUNCING
  uint8_t hold_timer;
#endif

#if UIBUTTONS_ENABLE_REPEAT_PRESS
  uint8_t repeat_timer;
#endif  
  
#if UIBUTTONS_ENABLE_MULTI_CLICK
  uint8_t click_timer;
  uint8_t click_count;
#endif  
 
}uibutton_t;


#define UIBUTTON(name) \
        bool uibuttons_get_##name(void); \
        uibutton_t name = {uibuttons_get_##name}; \
        bool uibuttons_get_##name(void)

#define EXTERN_UIBUTTON(name) \
        extern uibutton_t name

#define UIBUTTONS(...) \
    const uibutton_t *uibuttons[] = { __VA_ARGS__ }; \
    const unsigned uibuttons_count = sizeof(uibuttons)/sizeof(uibuttons[0]);

#define UIBUTTONS_COUNT uibuttons_count

#define UIBUTTONS_GET_ID(button) \
    ((int)(button-uibuttons))

#define UIBUTTONS_POLL_SINGLE(id) \
    uibuttons_poll(uibuttons[id])

#define UIBUTTONS_POLL_ALL() \
    do{int tmp;for(tmp=0;tmp<UIBUTTONS_COUNT;tmp++)UIBUTTONS_POLL_SINGLE(tmp);}while(0)
      
#define UIBUTTONS_INIT_ALL() \
      do{int tmp;for(tmp=0;tmp<UIBUTTONS_COUNT;tmp++)uibuttons[tmp]->prev_state=uibuttons[tmp]->get();}while(0)

void uibuttons_poll(uibutton_t *button);

#endif /* UIBUTTONS_H_ */
