if (MSVC)
    include(E:/Git_Repos/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif ()

if (APPLE)
    include_directories(/opt/homebrew/include)
endif ()
