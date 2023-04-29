/*
 * buttons.c
 *
 *  Created on: Apr 16, 2023
 *      Author: marco
 */


#include "buttons.h"
#include "myos.h"
#include "uibuttons_process.h"
#include "main.h"
#include "debug.h"

#if DEBUG_BUTTONS
#define DBG(...) DBG_FUNC(__VA_ARGS__)
#else
#define DBG(...)
#define DBG_PROCESS(...)
#endif

UIBUTTON(B1)
{
   return !HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
}

UIBUTTONS(&B1);


void buttons_init(void)
{
   process_start(&uibuttons_process,NULL);
}



#if UIBUTTONS_ENABLE_EDGES
void uibuttons_fire_rising_edge(uibutton_t *button)
{
   DBG("RISING\n");

}

void uibuttons_fire_falling_edge(uibutton_t *button)
{
   DBG("FALLING\n");

}

#endif

#if (UIBUTTONS_ENABLE_SINGLE_PRESS || UIBUTTONS_ENABLE_LONG_PRESS)
void uibuttons_fire_short_press(uibutton_t *button)
{


}
#endif

#if UIBUTTONS_ENABLE_LONG_PRESS
void uibuttons_fire_long_press(uibutton_t *button)
{

}

void uibuttons_fire_longer_press(uibutton_t *button)
{

}

void uibuttons_fire_longest_press(uibutton_t *button)
{

}

void uibuttons_fire_long_release(uibutton_t *button)
{

}

void uibuttons_fire_longer_release(uibutton_t *button)
{

}

void uibuttons_fire_longest_release(uibutton_t *button)
{

}

#endif

#if UIBUTTONS_ENABLE_REPEAT_PRESS

void uibuttons_fire_repeat_press(uibutton_t *button)
{
   if(button == &B1)
   {
      process_start(&batdetect,NULL);
   }

}

#endif

#if UIBUTTONS_ENABLE_MULTI_CLICK

void uibuttons_fire_single_click(uibutton_t *button)
{

}

void uibuttons_fire_double_click(uibutton_t *button)
{

}

void uibuttons_fire_triple_click(uibutton_t *button)
{

}

#endif

