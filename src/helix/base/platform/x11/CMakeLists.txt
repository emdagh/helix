cmake_minimum_required(VERSION 3.11)
project(helix.base.x11)

file(GLOB SRC *.cpp)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_link_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    helix.base
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/include/helix
    ${CMAKE_SOURCE_DIR}/include/helix/base
    ${CMAKE_SOURCE_DIR}/include/helix/core
    ${CMAKE_SOURCE_DIR}/include/helix/gfx
)