set(EXEC_SOURCES main.cpp)
add_executable(${EXECUTABLE_NAME} ${EXEC_SOURCES})
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_20)


target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})


add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
  "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2.dll"
  $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/SDL2.dll
  COMMENT "Copying SDL2.dll" VERBATIM
)

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/resources
  $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/resources
  COMMENT "Copying resources" VERBATIM
)

target_compile_options(${EXECUTABLE_NAME} PRIVATE /W4 /WX)
