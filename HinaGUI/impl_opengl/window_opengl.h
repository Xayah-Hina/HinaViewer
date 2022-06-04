#ifndef HINAGUI_OPENGLWINDOW_H
#define HINAGUI_OPENGLWINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"

#include "core/defines.h"
#include "core/window.h"

#include <string>

namespace HinaGUI::Core
{
    class OpenGLWindow : public Window
    {
    public:
        void init(const std::string &window_name, int width, int height, int pos_x, int pos_y, const Vector4r& background_color) final;
        void render(int camera_ID) final;
        void kill() final;

    public:
        HINA_INLINE void resize(int width, int height) override;

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

#endif //HINAGUI_OPENGLWINDOW_H
