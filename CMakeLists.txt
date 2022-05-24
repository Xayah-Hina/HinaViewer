cmake_minimum_required(VERSION 3.15)
project(LearnImGui)

set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/include)
add_subdirectory(libimgui)
add_subdirectory(samples)
