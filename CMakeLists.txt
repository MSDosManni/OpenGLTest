cmake_minimum_required(VERSION 3.7)
project(OpenGLTest VERSION 1.0 LANGUAGES CXX)

cmake_policy(VERSION 3.11)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw-3.3.2)
add_subdirectory(src)
add_subdirectory(glad)
