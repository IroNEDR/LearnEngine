file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB LIBRARY_SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(${LIBRARY_NAME} STATIC 
            ${LIBRARY_SOURCE_FILES}
            ${HEADER_LIST})




target_include_directories(
    ${LIBRARY_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include"
    )

target_link_libraries(${LIBRARY_NAME} PUBLIC
${STATIC_LIBRARIES}
${ADDITIONAL_LIBS}
)
