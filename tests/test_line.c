#include <stdio.h>
#include <stdlib.h>

#include "mygui/error.h"
#include "mygui/framebuffer.h"
#include "mygui/pixel.h"
#include "mygui/line.h"

//Remeber always do not use Pixel*(Pointer) it is nightmare

int main(void)
{
    FrameBuffer *fb = NULL;
    GuiError err = framebuffer_create(30, 30, &fb);
    int i = 0, j = 0;
    Pixel out_pixel;

    if(err != GUI_SUCCESS)
    {
        printf("Framebuffer creation failed: %d\n", err);
        return 1;
    }

    Pixel red = {
        .r = 255,
        .g = 0,
        .b = 0,
        .a = 255
    };

    err = draw_line(fb, 10, 10, 29, 10, red);

    if(err != GUI_SUCCESS)
    {
        printf("The ERROR is: %d\n", err);
        return 1;
    }

    for(j=0; j<(fb->height); j++)
    {
        for(i=0; i< (fb->width); i++)
        {
            pixel_get(fb, i, j, &out_pixel);

            if(out_pixel.a != 0)
                printf("#");
            else
                printf(" ");
        }

        printf("\n");
    }

    framebuffer_destroy(fb);
    return 0;
}