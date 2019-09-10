cmake_minimum_required(VERSION 3.14)
project(Turing_Machine)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_STANDARD 14)

add_executable(Turing_Machine main.cpp)
