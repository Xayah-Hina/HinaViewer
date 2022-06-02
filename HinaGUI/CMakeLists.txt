find_package(glad CONFIG REQUIRED)
find_package(OpenMesh REQUIRED)

set(DEPENDENCY_LIB libimgui ${OPENMESH_LIBRARIES} glad::glad)
file(GLOB_RECURSE HINA_GUI_SRC *.h *.cpp)
add_library(HinaGUI ${HINA_GUI_SRC})
target_include_directories(HinaGUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(HinaGUI PRIVATE ${DEPENDENCY_LIB})
add_definitions(-DHINAGUI_BUILTIN_DESC_DIR="${CMAKE_CURRENT_SOURCE_DIR}/builtin-desc/")
