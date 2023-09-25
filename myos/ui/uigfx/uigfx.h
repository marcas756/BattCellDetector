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

#ifndef UIGFX_H_
#define UIGFX_H_

#include <stdint.h>
#include <stdbool.h>


#define UIGFX_XRES            128
#define UIGFX_YRES            64
#define UIGFX_BPP             1

#if (UIGFX_BPP == 1)
typedef bool uigfx_color_t;
#else
#error "uigfx : color type not defined"
#endif


typedef struct {
    const uint8_t xsz;
    const uint8_t ysz;
    const void* data;
    const void (*draw)(uint8_t* buf, int16_t x0, int16_t y0, char ch, uigfx_color_t c);
}uigfx_font_t;

typedef struct {
   int16_t xpos,ypos;
   uint16_t xres, yres;
} uigfx_widget_t;

typedef struct {
    const uint8_t *data;
    uint16_t xres;
    uint16_t yres;
    uint8_t bbp;
} uigfx_image_t;






void uigfx_set_widget( uigfx_widget_t *widget );
void uigfx_init_widget(uigfx_widget_t *widget, int16_t xpos, int16_t ypos, uint16_t xres, uint16_t yres);
void uigfx_select_screen_widget();

const uigfx_widget_t uigfx_screen_widget;
uigfx_widget_t *uigfx_current_widget;



void uigfx_draw_pixel(uint8_t* buff, int16_t x, int16_t y, uigfx_color_t c);
void uigfx_draw_hline(uint8_t* buf, int16_t x0, int16_t y0, int16_t w, uigfx_color_t c);
void uigfx_draw_vline(uint8_t* buf, int16_t x0, int16_t y0, int16_t h, uigfx_color_t c);
void uigfx_draw_line(uint8_t* buf,int16_t x0, int16_t y0, int16_t x1, int16_t y1, uigfx_color_t c);
void uigfx_draw_rectangle(uint8_t* buf, int16_t x0, int16_t y0, int16_t l, int16_t h, uigfx_color_t c);
void uigfx_draw_filled_rectangle(uint8_t* buf, int16_t x0, int16_t y0, int16_t l, int16_t h, uigfx_color_t c);
void uigfx_draw_circle(uint8_t* buf, int16_t x0, int16_t y0, int16_t r,uigfx_color_t c);
void uigfx_draw_filled_circle(uint8_t* buf, int16_t x0, int16_t y0, int16_t r,uigfx_color_t c);
void uigfx_draw_ellipse(uint8_t* buf, int16_t x0, int16_t y0, int16_t a, int16_t b, uigfx_color_t c);
void uigfx_draw_filled_ellipse(uint8_t* buf, int16_t x0, int16_t y0, int16_t a, int16_t b, uigfx_color_t c);

void uigfx_draw_char(uint8_t* buf, uigfx_font_t *font, int16_t x0, int16_t y0, char ch, uigfx_color_t c);
void uigfx_draw_string(uint8_t* buf, uigfx_font_t *font, int16_t x0, int16_t y0, char* str, uigfx_color_t c);
int16_t uigfx_draw_put_char(uint8_t* buf, uigfx_font_t *font, int16_t x0, int16_t y0, char ch, uigfx_color_t c);
int16_t uigfx_string_newline(uigfx_font_t *font, int16_t y0);


void uigfx_draw_image(uint8_t* buf, uigfx_image_t *image, int16_t x0, int16_t y0);

#endif /* _UIGFX_H_ */
