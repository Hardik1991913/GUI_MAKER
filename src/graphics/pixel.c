#include<stdint.h>
#include<stdlib.h>
#include "mygui/framebuffer.h"
#include "mygui/pixel.h"
#include "mygui/error.h"

GuiError pixel_set(FrameBuffer* fb, int x, int y, Pixel apixel)
{
    if(fb == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->pixels == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->width <= 0 || fb->height <= 0)
        return GUI_INVALID_DIMENSIONS;

    if(x >= fb->width || x < 0)
        return GUI_OUT_OF_BOUNDS_ERROR;
    
    if(y >= fb->height || y < 0)
        return GUI_OUT_OF_BOUNDS_ERROR;
    
    fb->pixels[y*(fb->width)+x] = apixel;

    return GUI_SUCCESS;
}

GuiError pixel_get(FrameBuffer* fb, int x, int y, Pixel* out_pixel)
{
    if(out_pixel == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->pixels == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->width <= 0 || fb->height <= 0)
        return GUI_INVALID_DIMENSIONS;

    if(x >= fb->width || x < 0)
        return GUI_OUT_OF_BOUNDS_ERROR;
    
    if(y >= fb->height || y < 0)
        return GUI_OUT_OF_BOUNDS_ERROR;

    *(out_pixel) = fb->pixels[y*(fb->width)+x];

    return GUI_SUCCESS;
}