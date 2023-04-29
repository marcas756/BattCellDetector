/*
 * uileds_patterns_morse.h
 *
 *  Created on: 18.04.2023
 *      Author: marco
 */

#ifndef UILEDS_PATTERNS_MORSE_H_
#define UILEDS_PATTERNS_MORSE_H_

#include "uileds.h"

/*
The Basics
The timing in Morse code is based around the length of one "dit" (or "dot" if you like). From the dit length we can derive the length of a "dah" (or "dash") and the various pauses:

Dit: 1 unit
Dah: 3 units
Intra-character space (the gap between dits and dahs within a character): 1 unit
Inter-character space (the gap between the characters of a word): 3 units
Word space (the gap between two words): 7 units
*/


#define MORSE_DIT 1
#define MORSE_DAH 3
#define MORSE_INTRA_CHAR 1
#define MORSE_INTER_CHAR 3
#define MORSE_WORD_SPACE 7

#define MORSE_SCALE 5

#define UILEDS_PATTERN_MORSE(name) \
   UILEDS_PATTERN(name,11)

void uileds_set_morse_pattern(uileds_state_t *pattern, char character);

#define UILEDS_SET_MORSE_PATTERN(name,ch) \
      uileds_set_morse_pattern((uileds_state_t*)&uileds_pattern_##name,ch)





#endif /* UILEDS_PATTERNS_MORSE_H_ */
