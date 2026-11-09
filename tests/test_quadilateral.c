#include "mygui/quadrilateral.h"
#include "mygui/pixel.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
    FrameBuffer* fb = NULL;
    Pixel red = {
        255,
        0,
        0,
        255
    };
    GuiError err;
    Pixel out_pixel;

    Point P1={0,0},
          P2={12,5},
          P3={19,19},
          P4={5,12};

    err = framebuffer_create(31, 31, &fb);
    if(err!=GUI_SUCCESS)
    {
        printf("Error on frambuffer: %d\n", err);
        return 1;
    }

    err = draw_quadl(fb, P1, P2, P3, P4, red);
    if(err!=GUI_SUCCESS)
    {
        printf("Error on Quad: %d\n", err);
        return 1;
    }

    for(int j=0; j < fb->height; j++)
    {
        for(int i=0; i < fb->width; i++)
        {
            err = pixel_get(fb, i, j, &out_pixel);
            if(err!=GUI_SUCCESS)
            {
                printf("Error on Fetching Pixel: %d\n", err);
                return 1;
            }

            if(out_pixel.a != 0)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }

    framebuffer_destroy(fb);
    return 0;
}