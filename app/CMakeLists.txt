set(EXEC_SOURCES main.cpp)
add_executable(${EXECUTABLE_NAME} ${EXEC_SOURCES})
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_20)

include_directories("${CMAKE_SOURCE_DIR}/libs/GLFW/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/SDL2/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/GLEW/include")
include_directories(${CMAKE_SOURCE_DIR}/src)

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME}
# ${GLEW_STATIC_LIBRARIES}
# ${SDL_STATIC_LIBRARIES}
# ${GLFW_STATIC_LIBRARIES}
# ${ADDITIONAL_STATIC_LIBS}
)


add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
  "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2.dll"
  $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/SDL2.dll
  COMMENT "Copying DLLs" VERBATIM
)

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/shaders
  $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/shaders
  COMMENT "Copying shaders" VERBATIM
)

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/textures
  $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/textures
  COMMENT "Copying textures" VERBATIM
)

if(WIN32)
  target_compile_options(${EXECUTABLE_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()