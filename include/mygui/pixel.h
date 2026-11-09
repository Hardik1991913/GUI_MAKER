#ifndef GUI_MAKER_PIXEL_H
#define GUI_MAKER_PIXEL_H

#include "framebuffer.h"

GuiError pixel_set(FrameBuffer*, int, int, Pixel);
GuiError pixel_get(FrameBuffer*, int, int, Pixel*);

#endif