cmake_minimum_required(VERSION 3.21)
project(eigen-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)
include_directories(eigen)

# Set up Python, be sure to have NumPy installed
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

# Add pybind11 module
file(GLOB_RECURSE PYBIND11_SOURCE bindings/bindings.cpp bindings/bindereigen.cpp bindings/unknown/*.cpp)
pybind11_add_module(bindings ${PYBIND11_SOURCE})
install(TARGETS bindings LIBRARY DESTINATION .)
