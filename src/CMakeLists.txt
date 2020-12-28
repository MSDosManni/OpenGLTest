project(OpenGLTest_prog)

find_package(OpenGL REQUIRED)

add_executable(OpenGLTest OpenGLTest.cpp)

target_link_libraries(OpenGLTest glad)
target_link_libraries(OpenGLTest glfw)
