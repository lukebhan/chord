cmake_minimum_required(VERSION 3.15)
project(chord)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/include/openssl)
link_libraries(crypto)
add_executable(chord main.cpp Node.h Node.cpp)