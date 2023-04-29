/*
 * uileds_patterns.morse.c
 *
 *  Created on: 18.04.2023
 *      Author: marco
 */

#include "uileds_patterns_morse.h"
#include <ctype.h>

#define DIT    1
#define DAH    2
#define TRM    0

#define DIT_DURATION    (MORSE_DIT*MORSE_SCALE)
#define DAH_DURATION    (MORSE_DAH*MORSE_SCALE)
#define INTRA_DURATION  (MORSE_INTRA_CHAR*MORSE_SCALE)
#define INTER_DURATION  (MORSE_INTER_CHAR*MORSE_SCALE)
#define WORD_DURATION   (MORSE_WORD_SPACE*MORSE_SCALE-INTER)

#define MORSE_DIGITS_OFFSET         0x30
#define MORSE_LETTERS_LOWER_OFFSET  0x61
#define MORSE_LETTERS_UPPER_OFFSET  0x41

typedef uint16_t morse_code_t;

#define MORSE_ENCODE_SHIFT(m,s) \
   (m<<(s<<1))

#define MORSE_ENCODE(m0,m1,m2,m3,m4,m5,m6,m7) \
      (MORSE_ENCODE_SHIFT(m0,0)| \
      MORSE_ENCODE_SHIFT(m1,1)| \
      MORSE_ENCODE_SHIFT(m2,2)| \
      MORSE_ENCODE_SHIFT(m3,3)| \
      MORSE_ENCODE_SHIFT(m4,4)| \
      MORSE_ENCODE_SHIFT(m5,5)| \
      MORSE_ENCODE_SHIFT(m6,6)| \
      MORSE_ENCODE_SHIFT(m7,7))

const morse_code_t morse_letters [] = {
      MORSE_ENCODE(DIT,DAH,TRM,TRM,TRM,TRM,TRM,TRM),  //A
      MORSE_ENCODE(DAH,DIT,DIT,DIT,TRM,TRM,TRM,TRM),  //B
      MORSE_ENCODE(DAH,DIT,DAH,DIT,TRM,TRM,TRM,TRM),  //C
      MORSE_ENCODE(DAH,DIT,DIT,TRM,TRM,TRM,TRM,TRM),  //D
      MORSE_ENCODE(DIT,TRM,TRM,TRM,TRM,TRM,TRM,TRM),  //E
      MORSE_ENCODE(DIT,DIT,DAH,DIT,TRM,TRM,TRM,TRM),  //F
      MORSE_ENCODE(DAH,DAH,DIT,TRM,TRM,TRM,TRM,TRM),  //G
      MORSE_ENCODE(DIT,DIT,DIT,DIT,TRM,TRM,TRM,TRM),  //H
      MORSE_ENCODE(DIT,DIT,TRM,TRM,TRM,TRM,TRM,TRM),  //I
      MORSE_ENCODE(DIT,DAH,DAH,DAH,TRM,TRM,TRM,TRM),  //J
      MORSE_ENCODE(DAH,DIT,DAH,TRM,TRM,TRM,TRM,TRM),  //K
      MORSE_ENCODE(DIT,DAH,DIT,DIT,TRM,TRM,TRM,TRM),  //L
      MORSE_ENCODE(DAH,DAH,TRM,TRM,TRM,TRM,TRM,TRM),  //M
      MORSE_ENCODE(DAH,DIT,TRM,TRM,TRM,TRM,TRM,TRM),  //N
      MORSE_ENCODE(DAH,DAH,DAH,TRM,TRM,TRM,TRM,TRM),  //O
      MORSE_ENCODE(DIT,DAH,DAH,DIT,TRM,TRM,TRM,TRM),  //P
      MORSE_ENCODE(DAH,DAH,DIT,DAH,TRM,TRM,TRM,TRM),  //Q
      MORSE_ENCODE(DIT,DAH,DIT,TRM,TRM,TRM,TRM,TRM),  //R
      MORSE_ENCODE(DIT,DIT,DIT,TRM,TRM,TRM,TRM,TRM),  //S
      MORSE_ENCODE(DAH,TRM,TRM,TRM,TRM,TRM,TRM,TRM),  //T
      MORSE_ENCODE(DIT,DIT,DAH,TRM,TRM,TRM,TRM,TRM),  //U
      MORSE_ENCODE(DIT,DIT,DIT,DAH,TRM,TRM,TRM,TRM),  //V
      MORSE_ENCODE(DIT,DAH,DAH,TRM,TRM,TRM,TRM,TRM),  //W
      MORSE_ENCODE(DAH,DIT,DIT,DAH,TRM,TRM,TRM,TRM),  //X
      MORSE_ENCODE(DAH,DIT,DAH,DAH,TRM,TRM,TRM,TRM),  //Y
      MORSE_ENCODE(DAH,DAH,DIT,DIT,TRM,TRM,TRM,TRM),  //Z
};




const morse_code_t morse_digits [] = {
      MORSE_ENCODE(DAH,DAH,DAH,DAH,DAH,TRM,TRM,TRM),  //0
      MORSE_ENCODE(DIT,DAH,DAH,DAH,DAH,TRM,TRM,TRM),  //1
      MORSE_ENCODE(DIT,DIT,DAH,DAH,DAH,TRM,TRM,TRM),  //2
      MORSE_ENCODE(DIT,DIT,DIT,DAH,DAH,TRM,TRM,TRM),  //3
      MORSE_ENCODE(DIT,DIT,DIT,DIT,DAH,TRM,TRM,TRM),  //4
      MORSE_ENCODE(DIT,DIT,DIT,DIT,DIT,TRM,TRM,TRM),  //5
      MORSE_ENCODE(DAH,DIT,DIT,DIT,DIT,TRM,TRM,TRM),  //6
      MORSE_ENCODE(DAH,DAH,DIT,DIT,DIT,TRM,TRM,TRM),  //7
      MORSE_ENCODE(DAH,DAH,DAH,DIT,DIT,TRM,TRM,TRM),  //8
      MORSE_ENCODE(DAH,DAH,DAH,DAH,DIT,TRM,TRM,TRM),  //9
};


void uileds_set_morse_pattern(uileds_state_t *pattern, char character)
{
   morse_code_t code;

   if(isalpha(character))
   {
      if(islower(character))
      {
         code = morse_letters[character-MORSE_LETTERS_LOWER_OFFSET];
      }
      else
      {
         code = morse_letters[character-MORSE_LETTERS_UPPER_OFFSET];
      }
   }
   else if (isdigit(character))
   {
      code = morse_digits[character-MORSE_DIGITS_OFFSET];
   }
   else
   {
      // Question mark
      return;
   }

   while(code)
   {
      uint8_t symbol = code&0x03;
      pattern->lstate = UILEDS_STATE_ON;
      pattern->duration = (symbol==DIT)?(DIT_DURATION):(DAH_DURATION);
      pattern++;
      pattern->lstate = UILEDS_STATE_OFF;
      pattern->duration = INTRA_DURATION;
      pattern++;
      code>>=2;
   }

   pattern->lstate = UILEDS_STATE_OFF;
   pattern->duration = INTER_DURATION-INTRA_DURATION;
   pattern++;

   // finalize pattern
   pattern->lstate = 0;
   pattern->duration = 0;
}




