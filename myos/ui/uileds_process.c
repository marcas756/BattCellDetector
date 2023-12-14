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


#include "uileds_process.h"
#include "etimer.h"

PROCESS(uileds_process,uileds_process);
PROCESS_THREAD(uileds_process)
{
    static etimer_t et;

    PROCESS_BEGIN();

    etimer_start(&et, TIMESTAMP_TICKS_PER_SEC/50, PROCESS_THIS(), PROCESS_EVENT_TIMEOUT, NULL);

    while(1)
    {
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));

        do{
            uileds_handler();
            etimer_reset(&et);
        }while(etimer_expired(&et));
    }

    PROCESS_END();
}


