#include "window.h"

using namespace HinaGUI::Core;

void Window::init(const std::string &window_name, int width, int height, int pos_x, int pos_y, const Eigen::Vector4f &background_color)
{
    background_color_ = background_color;
    _init_opengl(window_name, width, height, pos_x, pos_y);
    _init_imgui();
}

void Window::kill()
{
    _kill_opengl_and_imgui();
    window_ = nullptr;
}

void Window::render()
{
    while (!glfwWindowShouldClose(window_))
    {
        if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window_, true);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        ImGui::Render();

        glClearColor(background_color_.x(), background_color_.z(), background_color_.y(), background_color_.w());
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}

void Window::_init_opengl(const std::string &window_name, int width, int height, int pos_x, int pos_y)
{
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 8); // MSAA samples
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window_ = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    glfwSetWindowPos(window_, pos_x, pos_y);
    glfwMakeContextCurrent(window_);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

void Window::_init_imgui()
{
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;

    // Setup Dear ImGui style
    ImGui::StyleColorsLight();
    ImGui_ImplGlfw_InitForOpenGL(window_, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    // TODO: Load Fonts
}

void Window::_kill_opengl_and_imgui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window_);
    glfwTerminate();
}
