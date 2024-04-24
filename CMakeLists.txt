cmake_minimum_required(VERSION 3.22.1)
project(sng)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)


add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/lexer.cpp
)