#ifndef HINAGUI_WINDOW_H
#define HINAGUI_WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"

#include "../base/defines.h"

#include <string>

namespace HinaGUI::Core
{
    class Window
    {
    public:
        void init(const std::string &window_name, int width, int height, int pos_x, int pos_y, const Eigen::Vector4f& background_color);
        void render();
        void kill();

    protected:
        void _init_opengl(const std::string &window_name, int width, int height, int pos_x, int pos_y);
        void _init_imgui();
        void _kill_opengl_and_imgui();

    protected:
        GLFWwindow *window_ = nullptr;
        Eigen::Vector4f background_color_;
    };
}
// TODO: support multi-backend

#endif //HINAGUI_WINDOW_H
