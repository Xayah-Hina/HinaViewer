function(add_sample EXAMPLE_NAME)
    message(${CMAKE_CURRENT_SOURCE_DIR})
    set(SAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_NAME})

    set(SHADERS "")
    file(GLOB GLOB_SHADERS ${SAMPLE_DIR}/*.sc)
    list(APPEND SHADERS ${GLOB_SHADERS})
    if (NOT ARG_COMMON AND NOT IOS AND NOT EMSCRIPTEN AND NOT ANDROID)
        foreach (SHADER ${SHADERS})
            add_bgfx_shader(${SHADER} ${EXAMPLE_NAME})
        endforeach ()
        source_group("Shader Files" FILES ${SHADERS})
    endif ()

    set(SOURCES "")
    if (APPLE)
        file(GLOB GLOB_SOURCES ${SAMPLE_DIR}/*.mm)
        list(APPEND SOURCES ${GLOB_SOURCES})
    endif ()
    file(GLOB GLOB_SOURCES ${SAMPLE_DIR}/*.c ${SAMPLE_DIR}/*.cpp ${SAMPLE_DIR}/*.h ${SAMPLE_DIR}/*.sc)
    list(APPEND SOURCES ${GLOB_SOURCES})
    add_executable(example-${EXAMPLE_NAME} WIN32 ${SOURCES})
    target_link_libraries(example-${EXAMPLE_NAME} example-common)
    if (MSVC)
        set_target_properties(example-${EXAMPLE_NAME} PROPERTIES LINK_FLAGS "/ENTRY:\"mainCRTStartup\"")
    endif ()
    if (BGFX_CUSTOM_TARGETS)
        add_dependencies(examples example-${EXAMPLE_NAME})
    endif ()
    if (IOS)
        set_target_properties(example-${EXAMPLE_NAME} PROPERTIES MACOSX_BUNDLE ON
                MACOSX_BUNDLE_GUI_IDENTIFIER example-${EXAMPLE_NAME}
                MACOSX_BUNDLE_BUNDLE_VERSION 0
                MACOSX_BUNDLE_SHORT_VERSION_STRING 0
                XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer")
    endif ()
    target_compile_definitions(example-${EXAMPLE_NAME} PRIVATE "-D_CRT_SECURE_NO_WARNINGS" "-D__STDC_FORMAT_MACROS" "-DENTRY_CONFIG_IMPLEMENT_MAIN=1")
    if (IOS OR WIN32)
        # on iOS we need to build a bundle so have to copy the data rather than symlink
        # and on windows we can't create symlinks
        add_custom_command(TARGET example-${EXAMPLE_NAME} COMMAND ${CMAKE_COMMAND} -E copy_directory ${BGFX_DIR}/examples/runtime/ $<TARGET_FILE_DIR:example-${EXAMPLE_NAME}>)
    else ()
        # For everything else symlink some folders into our output directory
        add_custom_command(TARGET example-${EXAMPLE_NAME} COMMAND ${CMAKE_COMMAND} -E create_symlink ${BGFX_DIR}/examples/runtime/font $<TARGET_FILE_DIR:example-${EXAMPLE_NAME}>/font)
        add_custom_command(TARGET example-${EXAMPLE_NAME} COMMAND ${CMAKE_COMMAND} -E create_symlink ${BGFX_DIR}/examples/runtime/images $<TARGET_FILE_DIR:example-${EXAMPLE_NAME}>/images)
        add_custom_command(TARGET example-${EXAMPLE_NAME} COMMAND ${CMAKE_COMMAND} -E create_symlink ${BGFX_DIR}/examples/runtime/meshes $<TARGET_FILE_DIR:example-${EXAMPLE_NAME}>/meshes)
        add_custom_command(TARGET example-${EXAMPLE_NAME} COMMAND ${CMAKE_COMMAND} -E create_symlink ${BGFX_DIR}/examples/runtime/shaders $<TARGET_FILE_DIR:example-${EXAMPLE_NAME}>/shaders)
        add_custom_command(TARGET example-${EXAMPLE_NAME} COMMAND ${CMAKE_COMMAND} -E create_symlink ${BGFX_DIR}/examples/runtime/text $<TARGET_FILE_DIR:example-${EXAMPLE_NAME}>/text)
        add_custom_command(TARGET example-${EXAMPLE_NAME} COMMAND ${CMAKE_COMMAND} -E create_symlink ${BGFX_DIR}/examples/runtime/textures $<TARGET_FILE_DIR:example-${EXAMPLE_NAME}>/textures)
    endif ()
endfunction()

add_sample(sample01)
