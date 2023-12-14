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
   if ( !ptimer->running )
   {
      ptlist_push_front(&ptimer_running_list,ptimer);

#if MYOSCONF_STATS
      if(++ptimer_list_size > myos_stats.ptlist_size_max)
      {
          myos_stats.ptlist_size_max = ptimer_list_size;
      }
#endif
   }

   ptimer->running = true;
   ptimer_next_stop_update(ptimer);
}

void ptimer_remove_from_list(ptimer_t *ptimer)
{
   if( ptimer->running )
   {
      ptimer->running = false;
      ptlist_erase(&ptimer_running_list,ptimer);

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

PROCESS(ptimer_process,ptimer_process);
PROCESS_THREAD(ptimer_process)
{
   PROCESS_BEGIN();

   ptlist_init(&ptimer_running_list);

   while(1)
   {
      PROCESS_WAIT_EVENT(PROCESS_EVENT_POLL);
      ptimer_pending = false;

      ptimer_t *curr;

      ptlist_foreach(&ptimer_running_list,curr)
      {
         if( ptimer_expired(curr) )
         {

#if MYOSCONF_STATS
            ptimer_list_size--;
#endif

            if( curr->handler )
            {
              curr->handler((void*)(curr));
            }

            ptimer_remove_from_list(curr)


            /* remove ptimer from list */
            ptlist_erase(&ptimer_running_list,curr);
            curr->running = false;




         }
         else
         {
            ptimer_next_stop_update(curr);
         }
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




