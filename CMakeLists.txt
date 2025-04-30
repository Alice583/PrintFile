cmake_minimum_required(VERSION 3.0.0)
project(labwork1 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_STATIC "-static-libgcc -static-libstdc++ -static")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_STATIC}" )


add_executable(PrintFile main.cpp
)

