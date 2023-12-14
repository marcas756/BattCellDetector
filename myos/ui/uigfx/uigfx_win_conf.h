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


#ifndef UIGFX_WIN_CONF_H_
#define UIGFX_WIN_CONF_H_

#include "fonts/uigfx_font4x6.h"
#include "fonts/uigfx_font8x8_c64.h"
#include "fonts/uigfx_font8x8_vic.h"

#define UIGFX_COLOR_BLACK  0
#define UIGFX_COLOR_WHITE  1

#define UIGFX_WIN_TITLE_FONT        uigfx_font8x8_c64
#define UIGFX_WIN_TITLE_FONT_COLOR  UIGFX_COLOR_BLACK
#define UIGFX_WIN_TITLE_BG_COLOR    UIGFX_COLOR_WHITE
#define UIGFX_WIN_TITLE_BORDER      1

#define UIGFX_WIN_BORDER_COLOR      UIGFX_WIN_TITLE_BG_COLOR
#define UIGFX_WIN_WIDGET_BG_COLOR   UIGFX_COLOR_BLACK




#endif /* UIGFX_UIGFX_WIN_CONF_H_ */
