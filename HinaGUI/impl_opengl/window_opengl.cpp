#include "window_opengl.h"

using namespace HinaGUI::Core;

void OpenGLWindow::init(const std::string &window_name, int width, int height, int pos_x, int pos_y, const Vector4r &background_color)
{
    background_color_ = background_color;
    _init_opengl(window_name, width, height, pos_x, pos_y);
    _init_imgui();
}

void OpenGLWindow::kill()
{
    _kill_opengl_and_imgui();
    window_ = nullptr;
}

void OpenGLWindow::render()
{
    while (!glfwWindowShouldClose(window_))
    {
        if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window_, true);

        _update_opengl_data();
        _update_imgui_data();

        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}

void OpenGLWindow::_init_opengl(const std::string &window_name, int width, int height, int pos_x, int pos_y)
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

void OpenGLWindow::_init_imgui()
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

void OpenGLWindow::_update_opengl_data()
{
    glClearColor(background_color_.x(), background_color_.y(), background_color_.z(), background_color_.w());
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWindow::_update_imgui_data()
{
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
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void OpenGLWindow::_kill_opengl_and_imgui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window_);
    glfwTerminate();
}

void OpenGLWindow::register_render_object(Renderable *renderable)
{
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, renderable->get_vertices_size(), renderable->get_vertices_data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, renderable->get_indices_size(), renderable->get_indices_data(), GL_STATIC_DRAW);

#ifdef HINA_USE_DOUBLE
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);
#else
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
#endif
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    renderable_list_[renderable] = VAO;
}
