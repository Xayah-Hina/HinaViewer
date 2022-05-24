set(ImGUI_LIB libimgui)
set(S1_NAME sample1)

add_executable(${S1_NAME} ${S1_NAME}/main.cpp)

target_include_directories(${S1_NAME} PRIVATE ../libimgui)
target_link_libraries(${S1_NAME} PRIVATE ${ImGUI_LIB})