/*! \copyright
 
   https://opensource.org/licenses/BSD-3-Clause
 
   Copyright 2013-2021 Marco Bacchi <marco@bacchi.at>
   
   Redistribution and use in source and binary forms, with or without 
   modification, are permitted provided that the following conditions are met:
   
   1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.
   
   2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

   3. Neither the name of the copyright holder nor the names of its 
   contributors may be used to endorse or promote products derived from this 
   software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
   POSSIBILITY OF SUCH DAMAGE.
*/


#include "myos.h"




static ptlist_t ptimer_running_list;
timestamp_t ptimer_next_stop = 0;
bool ptimer_pending = false;


#if MYOSCONF_STATS
size_t ptimer_list_size;
#endif

const process_event_t ptimer_poll_evt = {
      .to = &ptimer_process,
      .id = PROCESS_EVENT_POLL,
      .data = NULL
};


static void ptimer_next_stop_update(ptimer_t *ptimer)
{
   timestamp_t this_stop = timer_timestamp_stop(&ptimer->timer);

   if( ptimer_pending )
   {
      if( timestamp_less_than(this_stop,ptimer_next_stop) )
      {
         ptimer_next_stop = this_stop;
      }
   }
   else
   {
     ptimer_next_stop = this_stop;
     ptimer_pending = true;
   }
}

void ptimer_add_to_list(ptimer_t *ptimer)
{
   if ( !ptimer->running)
   {
      ptlist_push_front(&ptimer_running_list,ptimer);
      ptimer->running = true;

#if MYOSCONF_STATS
      if(++ptimer_list_size > myos_stats.ptlist_size_max)
      {
          myos_stats.ptlist_size_max = ptimer_list_size;
      }
#endif

   }

   ptimer_next_stop_update(ptimer);
}

void ptimer_remove_from_list(ptimer_t *ptimer)
{
   if( ptimer->running )
   {
      ptlist_erase(&ptimer_running_list,ptimer);
      ptimer->running = false;
#if MYOSCONF_STATS
      ptimer_list_size--;
#endif
   }
}


PROCESS(ptimer_process,ptimer_process);
PROCESS_THREAD(ptimer_process)
{
   PROCESS_BEGIN();

   ptlist_init(&ptimer_running_list);

   while(1)
   {
      PROCESS_WAIT_EVENT(PROCESS_EVENT_POLL);
      ptimer_pending = false;

      ptimer_t *curr = (ptimer_t*)ptlist_begin(&ptimer_running_list);

      while(curr != (ptimer_t*)ptlist_end(&ptimer_running_list))
      {
         ptimer_t *next = (ptimer_t*)ptlist_next(&ptimer_running_list,curr);

         if( ptimer_expired(curr) )
         {
            /* remove ptimer from list */
            ptlist_erase(&ptimer_running_list,curr);
            curr->running = false;
#if MYOSCONF_STATS
            ptimer_list_size--;
#endif

            if( curr->handler )
            {
              curr->handler((void*)(curr));
            }
         }
         else
         {
            ptimer_next_stop_update(curr);
         }

         curr = next;
      }
   }

   PROCESS_END();
}


void ptimer_start(ptimer_t* ptimer, timespan_t span, ptimer_handler_t handler)
{
   ptimer->handler = handler;
   timer_start(&ptimer->timer,span);
   ptimer_add_to_list(ptimer);
}

void ptimer_restart(ptimer_t* ptimer)
{
   timer_restart(&ptimer->timer);
   ptimer_add_to_list(ptimer);
}


void ptimer_reset(ptimer_t* ptimer)
{
   timer_reset(&ptimer->timer);
   ptimer_add_to_list(ptimer);
}



extern bool process_deliver_event(process_event_t *evt);


void ptimer_processing(void)
{

#if MYOSCONF_STATS
    rtimer_timestamp_t start;
    rtimer_timespan_t slicetime;
#endif

   if ( ptimer_pending && timestamp_passed(ptimer_next_stop) )
   {
        ptimer_pending = false;

#if MYOSCONF_STATS
        start = rtimer_now();
#endif

        process_deliver_event((process_event_t*)&ptimer_poll_evt);

#if MYOSCONF_STATS
        slicetime = (rtimer_timespan_t)RTIMER_TIMESTAMP_DIFF(rtimer_now(),start);

        if( ptimer_process.maxslicetime < slicetime )
        {
            ptimer_process.maxslicetime = slicetime;
        }
#endif
   }
}




