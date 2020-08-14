cmake_minimum_required(VERSION 3.0.0)

#使用gcc作为c编译器
SET(CMAKE_C_COMPILER /usr/bin/gcc)
#使用g++作为c++编译器
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

#设置编译采用的C++标准的版本
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

project(2.1nullptr VERSION 0.1.0)

add_executable(2.1nullptr 2.1nullptr.cpp)

