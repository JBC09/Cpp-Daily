cmake_minimum_required(VERSION 4.0)
project(dailyC__)

set(CMAKE_CXX_STANDARD 20)

add_executable(dailyC__ main.cpp
        string_view.cpp
        reference.cpp
)
