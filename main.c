#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include "core/error.h"
#include "mygui/framebuffer.h"

int main()
{
    FrameBuffer* fb = NULL;

    GuiError error = framebuffer_create(100, 100, &fb);

    if(error!=GUI_SUCCESS)
    {
        printf("FRAMEBUFFER CREATION FAILED, ERROR: %d\n", error);
        return 1;
    }
}