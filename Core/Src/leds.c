/*
 * leds.c
 *
 *  Created on: Apr 16, 2023
 *      Author: marco
 */

#include "leds.h"
#include "myos.h"
#include "uileds_process.h"
#include "main.h"

UILEDS_LED(LD2)
{
   HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, state);
}

UILEDS_LEDS(&LD2);

void leds_init()
{
   process_start(&uileds_process,NULL);
   UILEDS_SET_PATTERN(LD2,heart_beat,UILEDS_ORIG);
}
