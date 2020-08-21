cmake_minimum_required(VERSION 3.0.0)

#使用gcc作为c编译器
SET(CMAKE_C_COMPILER /usr/bin/gcc)
#使用g++作为c++编译器
SET(CMAKE_CXX_COMPILER /usr/bin/g++)
#采用C++20标准编译
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

# 如果CMAKE_BUILD_TYPE是DEBUG则用CMAKE_CXX_FLAGS_DEBUG作为编译选项
# Debug模式下"-g"，就可以直接用GDB调试程序了
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -pthread -Wall -g -ggdb")
# 如果CMAKE_BUILD_TYPE是RELEASE则用CMAKE_CXX_FLAGS_RELEASE作为编译选项
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -pthread -Wall")

project(regex_for_server VERSION 0.1.0)

# 查找第三方库 
# REQUIRED：表示该库没找到就直接使cmake失败
# COMPONENTS * *：表示后面这些是库里面具体要加载模块组件
find_package(Boost 1.71.0 REQUIRED)

# 判断是否找到了第三方库 
if(Boost_FOUND)  # XXX_FOUND(此处是Boost_FOUND)表示XXX库是否被找到了
    message ("boost found")  # 输出消息
    include_directories(${Boost_INCLUDE_DIRS})  # 包含已经找到的库的头文件(此处是Boost的头文件)
else()
    message (FATAL_ERROR "Cannot find Boost")  # FATAL_ERROR会错误终止cmake
endif()

add_executable(regex_for_server main.http.cpp)

add_executable(regex_for_server_https main.https.cpp)

target_link_libraries( regex_for_server ${Boost_LIBRARIES} )
