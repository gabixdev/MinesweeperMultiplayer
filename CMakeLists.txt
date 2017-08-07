# CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

# C++ Options
set(CMAKE_CXX_STANDARD 17)

# Project name
project(MSMP CXX)

# Release mode is the default mode
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif ()

# Include the config
include(Config.cmake)

# Add the sources
add_subdirectory("src")