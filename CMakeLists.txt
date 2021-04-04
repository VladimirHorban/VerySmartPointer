# CMakeList.txt : CMake project for VerySmartPointer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME "VerySmartPtr")

set(ICLUDE Include/SmartPtr.hpp)

project(${PROJECT_NAME} CXX)

add_library(${PROJECT_NAME} INTERFACE ${INCLUDE})


