file(GLOB srcs *.h *.cpp)
add_library(HinaViewer ${srcs})
target_link_libraries(HinaViewer example-common)
