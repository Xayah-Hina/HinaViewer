#ifndef HINAGUI_RENDERABLE_OPENGL_H
#define HINAGUI_RENDERABLE_OPENGL_H

#include "../core/renderable.h"

class RenderableOpenGL : public Renderable
{
public:
    unsigned int register_to_renderer() override;

protected:
    unsigned int VAO_ = UINT_MAX;
};


#endif //HINAGUI_RENDERABLE_OPENGL_H
