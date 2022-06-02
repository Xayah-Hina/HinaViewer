SUBDIR_LIST(SAMPLES ${CMAKE_CURRENT_SOURCE_DIR})

find_package(GLUT REQUIRED)

foreach (SAMPLE ${SAMPLES})
    add_executable(${SAMPLE} ${SAMPLE}/main.cpp)
    target_include_directories(${SAMPLE} PRIVATE ${CMAKE_SOURCE_DIR})
    target_link_libraries(${SAMPLE} PRIVATE HinaGUI GLUT::GLUT)
endforeach ()
