#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "mygui/pixel.h"

int main()
{
    int x = -1, y = 9; 
    FrameBuffer* fb = NULL;
    Pixel a = {.r=1, .g=3, .b=4, .a=5};
    Pixel b;
    framebuffer_create(100, 100, &fb);

    GuiError error1 = pixel_set(fb, x, y, a);
    GuiError error2 = pixel_get(fb, x, y, &b);

    if(error1!=GUI_SUCCESS || error2!=GUI_SUCCESS)
    {
        printf("Error in setting the pixel: %d\n", error1);
        printf("Error in getting the pixel: %d\n", error2);
        return 1;
    } else {
        printf("R:%d G:%d B:%d A:%d \n", b.r, b.g, b.b, b.a);
        printf("R:%d G:%d B:%d A:%d \n", a.r, a.g, a.b, a.a);
    }
    framebuffer_destroy(fb);
}