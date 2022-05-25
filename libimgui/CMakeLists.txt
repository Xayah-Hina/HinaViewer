find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB LIBIMGUI_SRC *.h *.cpp)
add_library(libimgui ${LIBIMGUI_SRC})
target_link_libraries(
        libimgui
        PUBLIC
        glfw
        OpenGL::GL
)
