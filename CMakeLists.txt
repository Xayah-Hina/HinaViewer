cmake_minimum_required(VERSION 3.15)
project(HinaViewer)

set(CMAKE_CXX_STANDARD 17)

include(cmake/mymacros.cmake)

option(BGFX_BUILD_EXAMPLES OFF)
option(BGFX_INSTALL OFF)
add_subdirectory(submodules/bgfx.cmake)
add_subdirectory(submodules/libigl)
include_directories(submodules/libigl/include)

add_subdirectory(src)
add_subdirectory(samples)
