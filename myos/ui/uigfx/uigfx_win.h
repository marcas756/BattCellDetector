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


#ifndef UIGFX_WIN_H_
#define UIGFX_WIN_H_

#include "uigfx.h"



typedef struct {
    char* title;
    uigfx_widget_t title_widget;
    uigfx_widget_t window_widget;
} uigfx_window_t;

void uigfx_draw_window(uint8_t* buff, uigfx_window_t *win);
void uigfx_init_window(uigfx_window_t *win, char* title, int16_t xpos, int16_t ypos, uint16_t xres, uint16_t yres);
uigfx_widget_t* uigfx_get_window_widget(uigfx_window_t *win);
void uigfx_draw_desktop_wallpaper(uint8_t* buff, uigfx_image_t *wallpaper);

#endif /* UIGFX_WIN_H_ */
