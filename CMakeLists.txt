cmake_minimum_required(VERSION 3.10.0)
project(hello_window VERSION 1.0.0)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(hello_window 
src/config.h
        src/Shader.h
dependencies/stb_image.h
src/main.cpp
dependencies/glad/glad.c
        src/Cube.h
        src/Camera.h
        src/Renderer.h
        src/App.h
        src/Mesh.h
        src/Object.h
        src/Scene.h
        src/Tetrahedron.h)

target_link_libraries(hello_window
    glfw
    OpenGL::GL
)

target_include_directories(hello_window PRIVATE dependencies)