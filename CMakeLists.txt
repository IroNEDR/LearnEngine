cmake_minimum_required(VERSION 3.10)

project(LearnEngine VERSION 0.1.0 LANGUAGES CXX)


set(LIBRARY_NAME "GameLib")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_NAME "LearnEngine")


add_subdirectory(src)

add_subdirectory(app)

