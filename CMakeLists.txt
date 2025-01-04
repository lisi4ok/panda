cmake_minimum_required(VERSION 3.29)
project(panda C)

set(PANDA_VERSION_MAJOR 0)
set(PANDA_VERSION_MINOR 1)
set(PANDA_VERSION_PATCH 0)
set(PANDA_VERSION "" CACHE STRING "Override Panda version string. Default is to find out with git.")

set(CMAKE_C_STANDARD 23)

add_executable(panda src/main.c)
