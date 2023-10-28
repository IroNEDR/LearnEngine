cmake_minimum_required(VERSION 3.10)

project(LearnEngine VERSION 0.1.0 LANGUAGES CXX)


set(LIBRARY_NAME "GameLib")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_NAME "LearnEngine")

set(STATIC_LIBRARIES 
  "${CMAKE_SOURCE_DIR}/libs/GLEW/lib/Release/x64/glew32s.lib"
  "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2.lib"
  "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2main.lib"
  "${CMAKE_SOURCE_DIR}/libs/GLFW/lib-vc2022/glfw3.lib"
)


include_directories("${CMAKE_SOURCE_DIR}/libs/GLFW/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/SDL2/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/GLEW/include")
include_directories(${CMAKE_SOURCE_DIR}/src)

set(ADDITIONAL_LIBS
    opengl32.lib
    user32.lib
    gdi32.lib
    shell32.lib
)

add_subdirectory(src)

add_subdirectory(app)


