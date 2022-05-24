find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

file(GLOB LIBIMGUI_SRC *.h *.cpp)
add_library(libimgui ${LIBIMGUI_SRC})
#target_include_directories(
#        libimgui
#        PRIVATE
#)
target_link_libraries(
        libimgui
        PUBLIC
        glfw
        OpenGL::GL
        GLEW::GLEW
)
