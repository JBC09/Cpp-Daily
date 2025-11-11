cmake_minimum_required(VERSION 4.0)
project(dailyC__)

set(CMAKE_CXX_STANDARD 20)

add_executable(dailyC__ main.cpp
        hidden/string_view.cpp
        hidden/reference.cpp
        hidden/simpleOOp.cpp
        functionTemplate.cpp
)
