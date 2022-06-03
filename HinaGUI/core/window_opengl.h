#ifndef HINAGUI_OPENGLWINDOW_H
#define HINAGUI_OPENGLWINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"

#include "../base/defines.h"
#include "../base/window.h"

#include <string>

namespace HinaGUI::Core
{
    class OpenGLWindow : public Window
    {
    public:
        void init(const std::string &window_name, int width, int height, int pos_x, int pos_y, const Vector4r& background_color) final;
        void render() final;
        void kill() final;

        HINA_INLINE void register_render_object(Renderable *renderable) override;

    protected:
        void _init_opengl(const std::string &window_name, int width, int height, int pos_x, int pos_y);
        void _init_imgui();

        void _update_opengl_data();
        void _update_imgui_data();

        void _kill_opengl_and_imgui();

    protected:
        GLFWwindow *window_ = nullptr;
        Vector4r background_color_;
    };
}
// TODO: support multi-backend (Vulkan etc.)

#endif //HINAGUI_OPENGLWINDOW_H
