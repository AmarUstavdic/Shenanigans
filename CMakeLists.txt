cmake_minimum_required(VERSION 3.0)
project(Shenanigans)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
