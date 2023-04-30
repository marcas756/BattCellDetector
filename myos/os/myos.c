/*! \copyright
 
   https://opensource.org/licenses/BSD-3-Clause
 
   Copyright 2013-2023 Marco Bacchi <marco@bacchi.at>
   
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

#if (MYOSCONF_STATISTICS)



myos_stats_t myos_stats;


PROCESS(idle_process,idle_process);
PROCESS_THREAD(idle_process)
{
   static timestamp_t start,stop;
   static rtimer_timestamp_t rtstart,rtstop;

   PROCESS_BEGIN();

   start = timestamp_now();
   rtstart = rtimer_now();

   while(1)
   {
      PROCESS_SUSPEND();

      rtstop = rtimer_now();
      stop = timestamp_now();


      if( TIMESTAMP_DIFF(stop,start) > 1 ) // more than one tick behind ?
      {
         myos_stats.errflags.realtime = 1;
      }

      rtstart = RTIMER_TIMESTAMP_DIFF(rtstop,rtstart);

      if ( rtstart > myos_stats.maxlaptime )
      {
         myos_stats.maxlaptime = rtstart;
      }

      start = stop;
      rtstart = rtstop;
   }

   PROCESS_END();
}
#endif

void myos_init(void)
{
    process_module_init();
    timestamp_module_init();
    timer_module_init();
    ptimer_module_init();
    ctimer_module_init();
    rtimer_init();

#if (MYOSCONF_STATISTICS)
    process_start(&idle_process,NULL);
#endif

}
