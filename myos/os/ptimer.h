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


#ifndef PTIMER_H_
#define PTIMER_H_

#include "myos.h"
#include <stdbool.h>



#if (MYOSCONF_PTIMER_LIST_TYPE == MYOSCONF_DLIST)

#include "dlist.h"
typedef dlist_t ptlist_t;
typedef dlist_node_t ptlist_node_t;
#define PTLIST_NODE_TYPE                              DLIST_NODE_TYPE
#define ptlist_init(listptr)                          dlist_init(listptr)
#define ptlist_erase(listptr,nodeptr)                 dlist_erase(listptr,nodeptr)
#define ptlist_next(listptr,nodeptr)                  dlist_next(listptr,nodeptr)
#define ptlist_push_front(listptr,nodeptr)            dlist_push_front(listptr,nodeptr)
#define ptlist_prev(listptr,nodeptr)                  dlist_prev(listptr,nodeptr)
#define ptlist_foreach(listptr,iterator)              dlist_foreach(listptr,iterator)
#define ptlist_find(listptr,nodeptr)                  dlist_findlistptr,nodeptr)
#define ptlist_begin(listptr)                         dlist_begin(listptr)
#define ptlist_end(listptr)                           dlist_end(listptr)
#define ptlist_empty(listptr)                         dlist_empty(listptr)

#else

#include "slist.h"
typedef slist_t ptlist_t;
typedef slist_node_t ptlist_node_t;
#define PTLIST_NODE_TYPE                              SLIST_NODE_TYPE
#define ptlist_init(listptr)                          slist_init(listptr)
#define ptlist_erase(listptr,nodeptr)                 slist_erase(listptr,nodeptr)
#define ptlist_next(listptr,nodeptr)                  slist_next(listptr,nodeptr)
#define ptlist_push_front(listptr,nodeptr)            slist_push_front(listptr,nodeptr)
#define ptlist_prev(listptr,nodeptr)                  slist_prev(listptr,nodeptr)
#define ptlist_foreach(listptr,iterator)              slist_foreach(listptr,iterator)
#define ptlist_find(listptr,nodeptr)                  slist_findlistptr,nodeptr)
#define ptlist_begin(listptr)                         slist_begin(listptr)
#define ptlist_end(listptr)                           slist_end(listptr)
#define ptlist_empty(listptr)                         slist_empty(listptr)
#define ptlist_foreach(listptr,iterator)              slist_foreach(listptr,iterator)

#endif


PROCESS_EXTERN(ptimer_process);

typedef struct ptimer_t ptimer_t;

typedef void (*ptimer_handler_t) (ptimer_t *data);

struct ptimer_t{
   PTLIST_NODE_TYPE;
   timer_t timer;
   ptimer_handler_t handler;
   bool running;
};


#define ptimer_module_init() process_start(&ptimer_process, NULL);
void ptimer_processing(void);
void ptimer_start(ptimer_t* ptimer, timespan_t span, ptimer_handler_t handler);
void ptimer_restart(ptimer_t* ptimer);
void ptimer_reset(ptimer_t* ptimer);
#define ptimer_stop(ptimerptr) ptimer_remove_from_list(ptimerptr);
#define ptimer_expired(ptimerptr)   timer_expired(&(ptimerptr)->timer)


#endif /* PTIMER_H_ */
