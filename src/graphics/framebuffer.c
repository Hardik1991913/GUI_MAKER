#include<stdlib.h>
#include<stdint.h>
#include "mygui/error.h"
#include "mygui/framebuffer.h"

GuiError framebuffer_create(int width, int height, FrameBuffer** out_fb)
{   
    if(out_fb == NULL)
        return GUI_POINTER_NULL_ERROR;
    
    //Checking everything is good before allocating memory
    *out_fb = NULL;

    if(width <= 0 || height <= 0)
        return GUI_INVALID_DIMENSIONS;

    size_t w = (size_t)width;
    size_t h = (size_t)height;

    if(w > SIZE_MAX / h)
        return GUI_OVERFLOW_ERROR;

    size_t count = w*h;

    if(count > SIZE_MAX / sizeof(Pixel))
        return GUI_OVERFLOW_ERROR;

    //Started memory allocation
    *out_fb = calloc(1, sizeof(FrameBuffer));

    if(*out_fb == NULL)
        return GUI_OUT_OF_MEMORY;
   
    (*out_fb)->pixels = calloc(count, sizeof(Pixel));

    if((*out_fb)->pixels == NULL)
    {
        free(*out_fb);
        *out_fb = NULL;
        return GUI_OUT_OF_MEMORY;
    }

    //since everything is alright i can now allocate it to the pointer and be done with it
    
    (*out_fb)->width = width;
    (*out_fb)->height = height;

    return GUI_SUCCESS;
}

void framebuffer_destroy(FrameBuffer* fb_ptr)
{
    if(fb_ptr == NULL)
        return;

    free(fb_ptr->pixels);
    free(fb_ptr);
}