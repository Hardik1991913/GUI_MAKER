#include<stdint.h>
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

typedef struct
{
    uint8_t r; //unsigned 1 byte from 0~255 for pixel values
    uint8_t g;
    uint8_t b;
    uint8_t a;
} Pixel;

typedef struct FrameBuffer
{
    int width;
    int height;
    Pixel* pixels;
};

#endif