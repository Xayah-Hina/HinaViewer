cmake_minimum_required(VERSION 3.15)
project(HinaGUI)
set(CMAKE_CXX_STANDARD 17)

include(cmake/mymacros.cmake)
include(cmake/check_platform.cmake)

START("LOADING EXTERNAL LIBS")
set(EXTERN_INCLUDE_DIR "")
add_subdirectory(extern)
LOG_LIST(EXTERN_INCLUDE_DIR "GLOBAL EXTERNAL INCLUDE DIRS")
include_directories(${EXTERN_INCLUDE_DIR})
END("EXTERNAL LIBS DONE")

#START("LOADING HINAGUI")
add_subdirectory(HinaGUI)
#END("HINAGUI DONE")

#START("LOADING SAMPLES")
add_subdirectory(samples)
#END("SAMPLES DONE")
