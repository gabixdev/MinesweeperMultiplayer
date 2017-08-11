# CMake version
cmake_minimum_required(VERSION 3.8)

# C++ Options
set(CMAKE_CXX_STANDARD 17)

# Project name
project(MSMP CXX)

# Set functions
set(MSMP_FUNCTIONS "${CMAKE_SOURCE_DIR}/cmake/" CACHE INTERNAL "MSMP functions directory")

# Set the binaries directory
set(MSMP_BIN_DIR ${CMAKE_SOURCE_DIR}/bin/ CACHE STRING "MSMP Binaries Directory")

# Set the libraries directory
set(MSMP_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/ CACHE STRING "MSMP Libraries Directory")

# Set modules directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

# Release mode is the default mode
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif ()

# Include the config
include(Config.cmake)

# Add the sources
add_subdirectory("src")