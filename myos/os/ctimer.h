/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */


/*!
   \file       ctimer.h
   \copyright  Copyright (c) 2006, Swedish Institute of Computer Science.
   \license    This file is released under the 3-Clause BSD License.\n
               https://opensource.org/license/bsd-3-clause/

   \brief   Callback timer implementation (ctimer)

   \details In computer programming, a callback or callback function is any
            reference to executable code that is passed as an argument to
            another piece of code; that code is expected to call back
            (execute) the callback function as part of its job. This
            execution may be immediate as in a synchronous callback, or it
            might happen at a later point in time as in an asynchronous
            callback. They are also called blocking and non-blocking.

            https://en.wikipedia.org/wiki/Callback_(computer_programming)

            Callback timer callbacks are asynchronous callbacks.

            The callback function gets invoked in the context of the process
            that started the callback timer.

*/


#ifndef CTIMER_H_
#define CTIMER_H_

#include "myos.h"

typedef struct ctimer_t ctimer_t;
typedef void (*ctimer_callback_t)(ctimer_t *ctimer);

struct ctimer_t {
   ptimer_t ptimer;     /*!< Instance of process timer control structure */
   process_t *context;  /*!< Context in which to invoke the callback function */
   ctimer_callback_t callback; /*!< Callback function to be called when process timer expires */
   void* data;
};

void ctimer_start(ctimer_t *ctimer, timespan_t span, ctimer_callback_t callback, void *data);
#define ctimer_module_init()        ptimer_module_init()
#define ctimer_restart(ctimerptr)   ptimer_restart((ptimer_t*)ctimerptr)
#define ctimer_reset(ctimerptr)     ptimer_rreset((ptimer_t*)ctimerptr)
#define ctimer_stop(ctimerptr)      ptimer_stop((ptimer_t*)ctimerptr)
#define ctimer_expired(ctimerptr)   ptimer_expired((ptimer_t*)ctimerptr)


#endif /* CTIMER_H_ */
