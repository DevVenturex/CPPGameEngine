cmake_minimum_required(VERSION 4.2)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CApp VERSION 0.1.0 LANGUAGES C CXX)

include(Dependencies.cmake)

add_subdirectory(Source/Core)
add_subdirectory(Source/App)
add_subdirectory(Source/Sandbox)