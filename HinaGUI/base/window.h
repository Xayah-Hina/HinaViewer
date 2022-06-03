#ifndef HINAGUI_WINDOW_H
#define HINAGUI_WINDOW_H

#include "defines.h"
#include "renderable.h"

#include <map>

class Window
{
public:
    virtual void init(const std::string &window_name, int width, int height, int pos_x, int pos_y, const Vector4r &background_color) = 0;
    virtual void render() = 0;
    virtual void kill() = 0;

    HINA_INLINE virtual void register_render_object(Renderable *renderable) = 0;

protected:
    std::map<Renderable *, unsigned int> renderable_list_; // first: Renderable Data Target, second: Object GPU ID, like VAO for OpenGL
};

#endif //HINAGUI_WINDOW_H
