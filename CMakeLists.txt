cmake_minimum_required(VERSION 3.30.1)
project(gameEngine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE FILES ./src/**.cpp)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ${FILES})

set(CMAKE_BUILD_TYPE Debug)

if(TARGET SDL2::SDL2main)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

target_include_directories(${PROJECT_NAME} PRIVATE src/headers)
