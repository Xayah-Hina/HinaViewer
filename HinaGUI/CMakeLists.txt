set(ImGUI_LIB libimgui)
file(GLOB_RECURSE HINA_GUI_SRC *.h *.cpp)
add_library(HinaGUI ${HINA_GUI_SRC})
target_link_libraries(HinaGUI PRIVATE ${ImGUI_LIB})
