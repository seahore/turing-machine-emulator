cmake_minimum_required(VERSION 2.8)
project(Turing_Machine_Sim)

add_definitions(-std=c++11)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(. DIR_SRC)
link_directories(/usr/lib)

add_executable(Turing_Machine_Sim ${DIR_SRC})
