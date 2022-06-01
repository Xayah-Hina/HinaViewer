add_library(libglad glad.c)
target_include_directories(
        libglad
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)