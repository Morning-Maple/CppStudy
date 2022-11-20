cmake_minimum_required(VERSION 3.21)
project(CppP2)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppP2 main.cpp workerManager.cpp workerManager.h worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)
