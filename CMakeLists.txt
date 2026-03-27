cmake_minimum_required(VERSION 3.10)

# You can change "MyGroupProject" to your actual project name
project(MyGroupProject VERSION 1.0)

# Set the C++ standard (C++17 is a good modern default)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake where to look for header files (.h / .hpp)
include_directories(include)

# Add your source files here as you create them
set(SOURCES
    src/main.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})
