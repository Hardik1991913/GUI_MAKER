#ifndef GUI_LINE_H
#define GUI_LINE_H

#include "mygui/error.h"
#include "mygui/framebuffer.h"
#include "mygui/pixel.h"

GuiError draw_line(FrameBuffer* fb, int x1, int y1, int x2, int y2, Pixel);

#endif