if (MSVC)
    include(E:/Git_Repos/vcpkg/scripts/buildsystems/vcpkg.cmake)
    find_path(VCPKG_INCLUDE_DIR zlib.h)
    include_directories(${VCPKG_INCLUDE_DIR})
endif ()

if (APPLE)
    include_directories(/opt/homebrew/include)
endif ()
