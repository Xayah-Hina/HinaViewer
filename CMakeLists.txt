cmake_minimum_required(VERSION 3.15)
project(HinaGUI)

set(CMAKE_CXX_STANDARD 17)

include(cmake/mymacros.cmake)
include(cmake/check_platform.cmake)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

option(BGFX_BUILD_EXAMPLES OFF)
option(BGFX_INSTALL OFF)
add_subdirectory(submodules/bgfx.cmake)
#add_subdirectory(src)
add_subdirectory(samples)
