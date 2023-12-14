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



#include "uileds.h"


void uileds_set_pattern (uileds_t* led, uileds_state_t* pattern, bool inverted)
{
    led->pattern=pattern;
    led->pstate=0;
    led->inverted = inverted;
}

void uileds_sync (uileds_t* which, uileds_t* with, bool inverted)
{
    which->pattern = with->pattern;
    which->pstate = with->pstate;
    which->timer = with->timer;
    which->inverted = with->inverted^inverted;
}


void uileds_handler()
{
    unsigned tmp;
    uileds_t *current;

    for (tmp=0; tmp<UILEDS_COUNT; tmp++)
    {
        current=(uileds_t*)uileds_all_leds[tmp];

        if (!current->pattern) continue;

        if(!current->timer)
        {
            current->timer=current->pattern[current->pstate].duration;
            current->set_led(current->pattern[current->pstate].lstate^current->inverted);

            if (!current->pattern[++current->pstate].duration)
            {
                current->pstate=0;
            }
        }

        current->timer--;
    }
}

