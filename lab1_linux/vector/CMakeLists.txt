cmake_minimum_required(VERSION 3.23)
project(vector)

set(CMAKE_CXX_STANDARD 17)

add_library(vector SHARED vector.cpp)

target_link_libraries(vector /home/ksenia/CLionProjects/number/cmake-build-debug/libnumber.a)

include_directories(/home/ksenia/CLionProjects/number)
