cmake_minimum_required(VERSION 3.10)
project(BlackJack)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# Add the source files
set(SOURCES
    src/main.cpp
)
include_directories(src)
# Add the executable target
add_executable(BlackJack ${SOURCES})