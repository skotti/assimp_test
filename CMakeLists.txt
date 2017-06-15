cmake_minimum_required(VERSION 3.4)
project(ass1)

message(STATUS ${CMAKE_MODULE_PATH})

find_package(ASSIMP REQUIRED)

message(STATUS ${ASSIMP_FOUND})


message(STATUS ${ASSIMP_INCLUDE_DIRS})
message(STATUS ${ASSIMP_LIBRARY_DIRS})

add_executable(ass main.cpp)

target_include_directories(ass PUBLIC ${ASSIMP_INCLUDE_DIRS})
target_link_libraries(ass PUBLIC ${ASSIMP_LIBRARIES})

target_compile_options(ass PUBLIC -g -std=c++14)
