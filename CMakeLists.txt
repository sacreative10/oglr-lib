cmake_minimum_required(VERSION 3.0)

project(oglr-lib)

add_executable(oglr-lib main.cpp)

install(TARGETS oglr-lib RUNTIME DESTINATION bin)
