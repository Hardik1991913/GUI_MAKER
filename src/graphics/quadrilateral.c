#include "mygui/error.h"
#include "mygui/framebuffer.h"
#include "mygui/types.h"
#include "mygui/pixel.h"
#include "mygui/line.h"

static GuiError Bound_Error_detector(FrameBuffer* fb, Point P)
{
    if(P.x >= fb->width || P.x<0 || P.y >= fb->height || P.y<0)
        return GUI_OUT_OF_BOUNDS_ERROR;

    return GUI_SUCCESS;
}

GuiError draw_quadl(FrameBuffer* fb,
    Point P1, 
    Point P2, 
    Point P3, 
    Point P4, 
    Pixel color)
{
    Point P[4] = {P1, P2, P3, P4};
    int k;
    GuiError err;

    if(fb == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->pixels == NULL)
        return GUI_POINTER_NULL_ERROR;

    if(fb->height <= 0 || fb->width <= 0)
        return GUI_INVALID_DIMENSIONS;

    for(k = 0; k<4; k++)
    {
        err = Bound_Error_detector(fb, P[k]);
        if(err!=GUI_SUCCESS)
            return err;
    }

    for(k=0; k<3; k++)
    {
        err = draw_line(fb, P[k+1].x, P[k+1].y, P[k].x, P[k].y, color);
        if(err!=GUI_SUCCESS)
            return err;
    }

    err = draw_line(fb, P[3].x, P[3].y, P[0].x, P[0].y, color);
    if(err!=GUI_SUCCESS)
        return err;
    
    return GUI_SUCCESS;
}
