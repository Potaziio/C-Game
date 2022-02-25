cmake_minimum_required(VERSION 3.0.0)
project(Katana_Engine VERSION 0.0.1)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

find_package(OpenGL REQUIRED)

file (GLOB KATANA_SOURCE_FILES
    "src/*.c"
    "src/*/*.c"
    "src/*/*/*.c"
    )

file(GLOB GLEW_SOURCES
    "libs/glew-2.2.0/src/*"
    )

file (GLOB INCLUDE_DIRS 
    "libs/glew-2.2.0/include/GL/*.h"
    "livs/stb_image/stb_image.h"
    )

add_subdirectory("libs/cglm/" cglm)
add_subdirectory("libs/glfw-3.3.5/" glfw)

include_directories(Katana_Engine ${KATANA_INCLUDE_FILES})

add_library(glew_lib STATIC ${GLEW_SOURCES})

add_executable(Katana_Engine ${KATANA_SOURCE_FILES})

target_link_libraries(Katana_Engine PUBLIC glew_lib glfw cglm OpenGL::GL ${CMAKE_DL_LIBS})
