#ifndef HINAGUI_WINDOW_H
#define HINAGUI_WINDOW_H

#include "defines.h"
#include "renderable.h"
#include "camera.h"
#include "light.h"
#include "shader.h"
#include "texture.h"

#include <map>

class Window
{
public:
    virtual void init(const std::string &window_name, int width, int height, int pos_x, int pos_y, const Vector4r &background_color) = 0;
    virtual void render(int camera_ID) = 0;
    virtual void kill() = 0;

public: // APIs
    HINA_INLINE virtual void resize(int width, int height) = 0;

public:
    HINA_INLINE size_t register_render_object(Renderable *renderable)
    {
        renderable_list_.emplace_back(renderable);
        return renderable_list_.size() - 1;
    }

    HINA_INLINE size_t register_shader(Shader *shader)
    {
        shaders_list_.emplace_back(shader);
        return shaders_list_.size() - 1;
    }

    HINA_INLINE size_t register_texture(Texture *texture)
    {
        textures_list_.emplace_back(texture);
        return textures_list_.size() - 1;
    }

    HINA_INLINE size_t register_camera(Camera *camera)
    {
        cameras_list_.emplace_back(camera);
        return cameras_list_.size() - 1;
    }

    HINA_INLINE size_t register_light(Light *light)
    {
        lights_list_.emplace_back(light);
        return lights_list_.size() - 1;
    }

protected:
    std::vector<Renderable *> renderable_list_; // first: Renderable Data Target, second: GPU Object ID, like VAO for OpenGL
    std::vector<Camera *> cameras_list_;
    std::vector<Light *> lights_list_;
    std::vector<Shader *> shaders_list_;
    std::vector<Texture *> textures_list_;
};

#endif //HINAGUI_WINDOW_H
