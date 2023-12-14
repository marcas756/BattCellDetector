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


#include "uigfx_win.h"
#include "uigfx_win_conf.h"
#include "string.h"
#include "uigfx.h"



void uigfx_draw_desktop_wallpaper(uint8_t* buff, uigfx_image_t *wallpaper)
{
    uigfx_widget_t *tmp = uigfx_current_widget;
    uigfx_set_widget((uigfx_widget_t*)&uigfx_screen_widget);

    for(uint16_t y = 0; y < uigfx_current_widget->yres; y+=wallpaper->yres)
    {
        for(uint16_t x = 0; x < uigfx_current_widget->xres; x+=wallpaper->xres)
        {
            uigfx_draw_image(buff,wallpaper,x,y);
        }
    }

    uigfx_set_widget(tmp);
}



void uigfx_draw_window(uint8_t* buff, uigfx_window_t *win)
{
    uigfx_widget_t *tmp = uigfx_current_widget;
    uigfx_set_widget(&win->title_widget);
    uigfx_draw_filled_rectangle(buff,0,0,win->title_widget.xres, win->title_widget.yres, UIGFX_WIN_TITLE_BG_COLOR);
    uigfx_draw_string(buff,(uigfx_font_t*)&UIGFX_WIN_TITLE_FONT,UIGFX_WIN_TITLE_BORDER,UIGFX_WIN_TITLE_BORDER,win->title,UIGFX_WIN_TITLE_FONT_COLOR);
    uigfx_set_widget(&win->window_widget);
    uigfx_draw_filled_rectangle(buff,0,0,win->window_widget.xres, win->window_widget.yres, UIGFX_WIN_WIDGET_BG_COLOR);
    uigfx_set_widget(tmp);
    uigfx_draw_rectangle(buff,win->title_widget.xpos-1,win->title_widget.ypos-1,win->title_widget.xres+2, win->title_widget.yres+win->window_widget.yres+2, UIGFX_WIN_BORDER_COLOR);
}

void uigfx_init_window(uigfx_window_t *win, char* title, int16_t xpos, int16_t ypos, uint16_t xres, uint16_t yres)
{
    win->title = title;
    win->title_widget.xpos = xpos;
    win->title_widget.ypos = ypos;

    win->title_widget.xres = strlen(title)*UIGFX_WIN_TITLE_FONT.xsz+ 2*UIGFX_WIN_TITLE_BORDER;

    if(xres > win->title_widget.xres)
    {
        win->title_widget.xres = xres;
    }

    win->title_widget.yres = UIGFX_WIN_TITLE_FONT.ysz + 2*UIGFX_WIN_TITLE_BORDER;

    win->window_widget.xpos = xpos;
    win->window_widget.ypos = ypos+win->title_widget.yres;
    win->window_widget.xres = win->title_widget.xres;
    win->window_widget.yres = yres-win->title_widget.yres;

}



void uigfx_select_window_widget(uigfx_window_t *win)
{
    uigfx_current_widget =  &win->window_widget;
}




