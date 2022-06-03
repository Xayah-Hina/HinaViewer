#ifndef HINAGUI_RENDERABLE_H
#define HINAGUI_RENDERABLE_H

#include "defines.h"

class Renderable
{
public:
    virtual Real *get_vertices_data() = 0;
    virtual int *get_indices_data() = 0;

    virtual int get_vertices_size() = 0;
    virtual int get_indices_size() = 0;

    enum
    {
        FILL = 1 << 0,
        WIREFRAME = 1 << 1,
        DONT_RENDER = 1 << 2
    } RENDERING_MODE = FILL;
};

#endif //HINAGUI_RENDERABLE_H
