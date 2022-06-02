#if (TARGET json)
#    return()
#endif ()
#
#include(FetchContent)
#if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#    set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fetched-content-Debug")
#else ()
#    set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fetched-content-Release")
#endif ()
#
#FetchContent_Declare(
#        json
#        GIT_REPOSITORY https://github.com/nlohmann/json.git
#        GIT_TAG v3.10.5
#)
#FetchContent_GetProperties(json)
#if (NOT json_POPULATED)
#    FetchContent_Populate(json)
#endif ()

SUBDIR_LIST(EXT_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach (EXT_DIR ${EXT_DIRS})
    add_subdirectory(${EXT_DIR})
    set(TEMP_INCLUDE ${TEMP_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/${EXT_DIR})
endforeach()

set(EXTERN_INCLUDE_DIR ${TEMP_INCLUDE} PARENT_SCOPE)
