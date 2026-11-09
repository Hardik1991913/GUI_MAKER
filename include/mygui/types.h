#ifndef GUI_TYPE_H
#define GUI_TYPE_H

#include<stdint.h>
#include<stdlib.h>

typedef int32_t GUI_Coord;
typedef uint32_t GUI_Dimensions;
typedef size_t GUI_SIZE;

typedef struct
{
    GUI_Coord x;
    GUI_Coord y;
} Point;


#endif