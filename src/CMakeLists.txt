set(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")


set(LIBRARY_SOURCE_FILES 
    "Sprite.cpp"
    "Errors.cpp"
    "MainGame.cpp"
    "GLSLProgram.cpp")



add_library(${LIBRARY_NAME} STATIC 
            ${LIBRARY_SOURCE_FILES}
            ${HEADER_LIST})




include_directories("${CMAKE_SOURCE_DIR}/libs/GLFW/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/SDL2/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/GLEW/include")
target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
    )

target_link_libraries(${LIBRARY_NAME} PRIVATE
${GLEW_STATIC_LIBRARIES}
${SDL_STATIC_LIBRARIES}
${GLFW_STATIC_LIBRARIES}
)
