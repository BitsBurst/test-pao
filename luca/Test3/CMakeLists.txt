cmake_minimum_required(VERSION 3.27)
project(Test3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.0/mingw_64/lib/cmake")

include_directories(.)

add_executable(Test3
        main.cpp
        mainwindow.cpp
        mainwindow.h)
