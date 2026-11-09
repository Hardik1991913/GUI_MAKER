#include<stdlib.h>
#include<stdint.h>
#include "mygui/error.h"
#include "mygui/framebuffer.h"
#include "mygui/pixel.h"

GuiError draw_line(FrameBuffer* fb, 
                int x1, int y1, 
                int x2, int y2, Pixel p)
{
    //Error handeling

    if(fb == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->pixels == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->height <= 0 || fb->width <= 0)
        return GUI_INVALID_DIMENSIONS;

    if(x1 >= fb->width || x2 >= fb->width || x1<0 || x2<0
        || y1 >= fb->height || y2 >= fb->height || y1<0 || y2<0)
        return GUI_OUT_OF_BOUNDS_ERROR;


    //The function defining these
    GuiError err;
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int y = y1;
    int x = x1;
    int k = 0;
    int D = 0;
    int sx = (x1<x2)?1:-1;
    int sy = (y1<y2)?1:-1;

    if(dx)
    {
        if(dx>=dy)
        {
            D = 2*dy - dx;

            for(k = 0; k<=dx; k++)
            {
                err = pixel_set(fb, x1+sx*k, y, p);

                if(err != GUI_SUCCESS)
                    return err;

                if(D>0)
                {
                    y+=sy;
                    D=D-2*dx;
                }

                D=D+2*dy;
            }
        }
        else
        {
            D = 2*dx - dy;
            for(k = 0; k<=dy; k++)
            {
                if(D>0)
                {
                    x+=sx;
                    D=D-2*dy;
                }
                err = pixel_set(fb, x, y1+sy*k, p);

                if(err!=GUI_SUCCESS)
                    return err;

                D=D+2*dx;
            }
        }
    }
    else
    {
        while(k<=dy)
        {
            err = pixel_set(fb, x1, y1+sy*k, p);

            if(err!=GUI_SUCCESS)
                return err;

            k++;
        }
    }

    return GUI_SUCCESS;
}