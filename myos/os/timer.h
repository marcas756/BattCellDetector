/*
 * Copyright (c) 2004, Swedish Institute of Computer Science.
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
 * Author: Adam Dunkels <adam@sics.se>
 *
 */


/*!
    \file       timer.h

    \brief

    \details
*/

#ifndef  TIMER_H_
#define  TIMER_H_

#include "timestamp.h"
#include <stdbool.h>

/* required due to redefinition of timer_t in /usr/include/x86_64-linux-gnu/bits/types/timer_t.h for linux host build */
typedef struct {
    timestamp_t start;
    timespan_t span;
}myos_timer_t ;

#define timer_t myos_timer_t

void timer_start(timer_t *timer, timespan_t span);


/*!
    \brief      Resets a previously set timer
    \details    Adds the currently set timespan to the timers start time.

    \param[in]      timer       Timer instance to reset
*/
void timer_reset(timer_t *timer);

/*!
    \brief      Restarts a previously set timer
    \details    Restarts a previously set timer. Be aware of that the timer must have
                been set properly before, otherwise behaviour is undefined.

    \param[in]      timer       Timer instance to restart
*/
void timer_restart(timer_t *timer);


#define timer_timestamp_stop(timerptr) \
      ((timerptr)->start + (timerptr)->span)

/*!
    \brief      Check if timer expired
    \details    Checks if timer expired. Timer will expire as soon as the time span
                provided with timer_start is elapsed.

    \param[in]      timer       Timer instance to check
    \returns    true if timer expired, false otherwise
*/
#define timer_expired(timerptr) \
      timestamp_passed(timer_timestamp_stop(timerptr))

#define timer_module_init timestamp_module_init


#endif /*  TIMER_H_ */
