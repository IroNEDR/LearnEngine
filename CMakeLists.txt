cmake_minimum_required(VERSION 3.10)

project(GameEngine VERSION 0.1.0 LANGUAGES CXX)


set(LIBRARY_NAME "GameLib")
# include(FetchContent)


# FetchContent_Declare(
#   GLEW
#   GIT_REPOSITORY https://github.com/nigels-com/glew
#   GIT_TAG glew-2.2.0
#   GIT_SHALLOW TRUE
#   )
# FetchContent_MakeAvailable(GLEW)
# find_package(GLEW 2.1 REQUIRED)
# FetchContent_Declare(
#   SDL
#   GIT_REPOSITORY https://github.com/libsdl-org/SDL
#   GIT_TAG release-2.28.4
#   GIT_SHALLOW TRUE
#   )
# FetchContent_MakeAvailable(SDL)
# find_package(SDL2 REQUIRED)
# find_package(GLFW3 3.3 REQUIRED)
# FetchContent_Declare(
#   glfw
#   GIT_REPOSITORY https://github.com/glfw/glfw
#   GIT_TAG 3.3.8
#   GIT_SHALLOW TRUE
#   )
# FetchContent_MakeAvailable(glfw)
# find_package(GLFW3 REQUIRED)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_NAME "GameEngine")


add_subdirectory(src)

add_subdirectory(app)

