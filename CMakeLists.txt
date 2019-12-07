cmake_minimum_required(VERSION 3.14)
project(scheduler_ElanaFelsi)

set(CMAKE_CXX_STANDARD 98)

add_executable(scheduler_ElanaFelsi main.cpp task.h scheduler.h time.h scheduler.cpp)