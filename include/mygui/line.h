#ifndef GUI_LINE_H
#define GUI_LINE_H

#include "mygui/error.h"
#include "mygui/framebuffer.h"
#include "mygui/pixel.h"

GuiError draw_line(FrameBuffer*, int, int, int, int, Pixel);

#endif