cmake_minimum_required(VERSION 3.10)

# Project name
project(Quantum_CipherBB84)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include the header files directory
include_directories(include)

# Add the source files
add_executable(Quantum_CipherBB84
    src/main.cpp
    src/Alice.cpp
    src/Bob.cpp
    src/BB84Protocol.cpp
)