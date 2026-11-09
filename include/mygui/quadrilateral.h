#ifndef GUI_QUADRILATERAL_H
#define GUI_QUADRILATERAL_H

#include "mygui/error.h"
#include "mygui/framebuffer.h"
#include "mygui/types.h"

//I mean this is Best
GuiError draw_quadl(FrameBuffer* fb,
    Point P1, 
    Point P2, 
    Point P3, 
    Point P4, 
    Pixel color);

#endif