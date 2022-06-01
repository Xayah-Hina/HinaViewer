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
// default OpenGL backend window, TODO: support multi-backend
    class Window
    {
    public:
        void init(const std::string &window_name, int width, int height, int pos_x = 0, int pos_y = 0);
        void render();
        void kill();

    protected:
        void init_opengl(const std::string &window_name, int width, int height, int pos_x = 0, int pos_y = 0);
        void init_imgui();
        void kill_opengl();
        void kill_imgui();

    protected:
        GLFWwindow *window_ = nullptr;
        Eigen::Vector4f background_color_ = COLOR::WHITE;
    };
}

#endif //HINAGUI_WINDOW_H
