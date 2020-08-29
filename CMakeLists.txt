cmake_minimum_required(VERSION 3.15)
project(chord)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/include/openssl)
link_libraries(crypto)
add_executable(chord main.cpp src/Node.h src/Node.cpp src/Helpers.cpp src/Helpers.h src/constants.h src/Finger.h)