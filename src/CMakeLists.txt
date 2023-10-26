file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")

set(GLEW_STATIC_LIBRARIES 
    "${CMAKE_SOURCE_DIR}/libs/GLEW/lib/Release/x64/glew32s.lib"
)

set(SDL_STATIC_LIBRARIES 
    "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2.lib"
    "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2main.lib"
)

set(GLFW_STATIC_LIBRARIES 
    "${CMAKE_SOURCE_DIR}/libs/GLFW/lib-vc2022/glfw3.lib"
)

set(ADDITIONAL_STATIC_LIBS
    opengl32.lib
    user32.lib
    gdi32.lib
    shell32.lib
)

set(LIBRARY_SOURCE_FILES 
    "Sprite.cpp"
    "Errors.cpp"
    "MainGame.cpp"
    "GLSLProgram.cpp"
    "IOManager.cpp"
    "picoPNG.cpp"
    "ImageLoader.cpp")



add_library(${LIBRARY_NAME} STATIC 
            ${LIBRARY_SOURCE_FILES}
            ${HEADER_LIST})




include_directories("${CMAKE_SOURCE_DIR}/libs/GLFW/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/SDL2/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/GLEW/include")
target_include_directories(
    ${LIBRARY_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include"
    )

target_link_libraries(${LIBRARY_NAME} PUBLIC
${GLEW_STATIC_LIBRARIES}
${SDL_STATIC_LIBRARIES}
${GLFW_STATIC_LIBRARIES}
${ADDITIONAL_STATIC_LIBS}
)
