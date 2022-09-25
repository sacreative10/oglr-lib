cmake_minimum_required(VERSION 3.0)

project(oglr-lib VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} -fPIC)
set(SPDLOG_BUILD_SHARED ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(external/glfw)
add_subdirectory(external/spdlog)


add_library(oglr-lib SHARED
external/glad/include/glad/glad.h external/glad/glad.c
"include/oglr/extra/logger.hpp" src/logger.cpp
"include/oglr/window.hpp" src/window.cpp
"include/oglr/application.hpp" src/application.cpp
"include/oglr/oglr.h")

target_link_libraries(oglr-lib PUBLIC spdlog::spdlog glfw)
target_include_directories(oglr-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include/)
