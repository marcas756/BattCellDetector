/*
 * Copyright (c) 2005, Swedish Institute of Computer Science
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
    \file       module.h
    \authors

    \brief      Brief description of the module

    \details    Detailed description of the module
*/

#ifndef PROCESS_H_
#define PROCESS_H_

#include "myosconf.h"
#include "pt.h"
#include "ringbuffer.h"
#include <stdbool.h>
#include "rtimer.h"

/**
 * @file
 * @brief Configuration for the type of list used for the running process list in myos.
 *
 * @details
 * This section of the code allows for the configuration of the type of list used to manage
 * the running processes in the operating system. The type of list can be specified in the
 * myos configuration file. By default, a singly linked list is used.
 *
 * The configuration can be modified to use a doubly linked list by defining the
 * MYOSCONF_DLIST macro in the configuration file. If MYOSCONF_DLIST is defined, the
 * corresponding doubly linked list implementation will be used; otherwise, the default
 * singly linked list implementation (slist) is utilized.
 *
 * The list type affects how processes are stored, accessed, and manipulated during
 * execution. The choice between a singly or doubly linked list can have implications
 * for performance and memory usage, depending on the specific needs and constraints of
 * the system.
 *
 * Singly Linked List Implementation:
 * - A singly linked list (slist) is used when MYOSCONF_DLIST is not defined.
 * - The singly linked list provides a simple and memory-efficient way to manage the
 *   running processes with basic operations like initialization, addition, deletion,
 *   and iteration over the list.
 *
 * Example of configuring a singly linked list for process management:
 * \code{.c}
 * #define MYOSCONF_PROC_LIST_TYPE MYOSCONF_SLIST
 * \endcode
 *
 * @note Currently, only the singly linked list implementation is supported. The
 *       implementation for the doubly linked list (dlist) is planned for future
 *       development.
 */
#if (MYOSCONF_PROC_LIST_TYPE == MYOSCONF_DLIST)
#else
#include "slist.h"
typedef slist_t plist_t;
typedef slist_node_t plist_node_t;
#define PLIST_NODE_TYPE                              SLIST_NODE_TYPE
#define plist_init(listptr)                          slist_init(listptr)
#define plist_erase(listptr,nodeptr)                 slist_erase(listptr,nodeptr)
#define plist_next(listptr,nodeptr)                  slist_next(listptr,nodeptr)
#define plist_push_front(listptr,nodeptr)            slist_push_front(listptr,nodeptr)
#define plist_prev(listptr,nodeptr)                  slist_prev(listptr,nodeptr)
#define plist_foreach(listptr,iterator)              slist_foreach(listptr,iterator)
#endif


/**
 * @def PROCESS_EVENT_QUEUE_SIZE
 * @brief Defines the size of the process event queue.
 *
 * @details
 * This macro sets the size of the event queue used by the process scheduler. The size determines
 * how many events can be queued at one time before the system starts dropping or ignoring new events.
 *
 * If the macro `MYOSCONF_PROC_EVENT_QUEUE_SIZE` is defined in the myos configuration file, its value
 * is used to set the size of the event queue. If it is not defined, a default size of 8 is used.
 *
 * Adjusting the event queue size can have implications on the system's performance and memory usage.
 * A larger queue size can handle more events but requires more memory, whereas a smaller queue size
 * conserves memory but may lead to dropped events in high-load scenarios.
 *
 * Example of configuring a custom event queue size:
 * \code{.c}
 * // In the myos configuration file
 * #define MYOSCONF_PROC_EVENT_QUEUE_SIZE 16
 * \endcode
 *
 * @note The configuration of the event queue size should be carefully considered based on the expected
 *       workload and available system resources.
 */
#ifdef MYOSCONF_PROC_EVENT_QUEUE_SIZE
#define PROCESS_EVENT_QUEUE_SIZE    MYOSCONF_PROC_EVENT_QUEUE_SIZE
#else
#define PROCESS_EVENT_QUEUE_SIZE    8
#endif


/**
 * @def PROCESS_EVENT_START
 * @brief Event indicating that a process is starting.
 *
 * @details
 * This event is posted to a process when it is starting. It can be used by the process to perform
 * initialization tasks. The process receives this event only once when it is first started.
 */
#define PROCESS_EVENT_START     0

/**
 * @def PROCESS_EVENT_POLL
 * @brief Event for polling a process.
 *
 * @details
 * This event is used to poll a process, typically to request it to update its state.
 * The process receives this event when the system or another process explicitly requests
 * a status update or immediate attention from the process.
 */
#define PROCESS_EVENT_POLL      1

/**
 * @def PROCESS_EVENT_CONTINUE
 * @brief Event to signal a process to continue its operation.
 *
 * @details
 * This event is used to signal a process to continue its execution, usually after being
 * suspended or waiting for a condition. It is a way to resume the process's activity
 * programmatically.
 */
#define PROCESS_EVENT_CONTINUE  2

/**
 * @def PROCESS_EVENT_TIMEOUT
 * @brief Event indicating a timeout has occurred.
 *
 * @details
 * This event is posted to a process when a specified time duration has elapsed.
 * It is often used for handling time-related tasks, such as periodic updates or
 * timeouts in response to external events.
 */
#define PROCESS_EVENT_TIMEOUT   3

/**
 * @def PROCESS_EVENT_EXIT
 * @brief Event indicating that a process is exiting.
 *
 * @details
 * This event is sent to a process when it is about to exit or terminate. It allows
 * the process to perform any necessary cleanup before it stops executing. Processes
 * can also use this event to signal other processes about their termination.
 */
#define PROCESS_EVENT_EXIT      4



typedef struct process_event_t process_event_t;
typedef struct process_t process_t;
typedef int(*process_thread_t)(process_t *process, process_event_t *evt);


struct process_t {
   PLIST_NODE_TYPE;
   process_thread_t thread;
   void* data;
   pt_t pt;

#if (MYOSCONF_STATS)
   rtimer_timespan_t maxslicetime;
#endif

   bool pollreq;
};


struct process_event_t {
   process_event_id_t id;
   void *data;
   process_t *from;
   process_t *to;
};


extern process_t *process_current;
#define PROCESS_THIS() process_current

#define PROCESS_CONTEXT_BEGIN(processptr) \
      do{ \
         process_t *process_backup; \
         process_backup = PROCESS_THIS(); \
         PROCESS_THIS() = processptr

#define PROCESS_CONTEXT_END() \
         PROCESS_THIS() = process_backup; \
      }while(0)


#define PROCESS(name,threadname) \
   int process_thread_##threadname(process_t *process, process_event_t *evt);  \
   process_t name = {{0},process_thread_##threadname,0,{0},false}

#define PROCESS_EXTERN(name) \
      extern process_t name

#define PROCESS_DATA()            (process->data)
#define PROCESS_PT()              (process->pt)
#define PROCESS_EVENT_DATA()      (evt->data)
#define PROCESS_EVENT_ID()        (evt->id)


#define EXTERN_PROCESS(name) \
   extern process_t name

#define PROCESS_THREAD(name) \
int process_thread_##name(process_t *process, process_event_t *evt)


#define PROCESS_RESPOND(evtid,dataptr) \
   process_respond(evt,evtid,dataptr)

#define PROCESS_INIT(processptr,threadname) \
   process_init(processptr, process_thread_##threadname)

#define PROCESS_IS_RUNNING(processptr) \
   (PT_IS_RUNNING(&(processptr)->pt))


#define PROCESS_BEGIN() \
   if(PROCESS_EVENT_ID() == PROCESS_EVENT_EXIT) {PT_EXIT(&PROCESS_PT());} \
   PT_BEGIN(&PROCESS_PT())



#define PROCESS_END()                   PT_END(&PROCESS_PT())
#define PROCESS_WAIT_EVENT(evtid)       PT_YIELD_UNTIL(&PROCESS_PT(), PROCESS_EVENT_ID() == evtid)
#define PROCESS_WAIT_EVENT_UNTIL(cond)  PT_YIELD_UNTIL(&PROCESS_PT(), cond)
#define PROCESS_WAIT_ANY_EVENT()        PT_YIELD(&PROCESS_PT())



#define PROCESS_SUSPEND() \
   do{ \
      process_post(PROCESS_THIS(),PROCESS_EVENT_CONTINUE,NULL); \
      PROCESS_WAIT_EVENT(PROCESS_EVENT_CONTINUE); \
   }while(0)


/**
 * Specify an action when a process exits.
 *
 * \note This declaration must come immediately before the
 * PROCESS_BEGIN() macro.
 *
 * \param handler The action to be performed.
 *
 * \hideinitializer
 */
#define PROCESS_EXITHANDLER(handler) if(PROCESS_EVENT_ID() == PROCESS_EVENT_EXIT) { handler; }



void process_init(void);
void process_init_process( process_t *process, process_thread_t thread );
bool process_start(process_t *process, void* data);
bool process_exit(process_t *process);
bool process_post(process_t *to, process_event_id_t evtid, void* data);
bool process_post_sync(process_t *to, process_event_id_t evtid, void* data);
int process_run(void);
void process_poll(process_t *process);

#endif /* PROCESS_H_ */


















