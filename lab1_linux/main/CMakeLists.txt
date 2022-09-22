cmake_minimum_required(VERSION 3.23)
project(main)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)

target_link_libraries(main /home/ksenia/CLionProjects/number/cmake-build-debug/libnumber.a)

include_directories(/home/ksenia/CLionProjects/number)

target_link_libraries(main /home/ksenia/CLionProjects/vector/cmake-build-debug/libvector.so)

include_directories(/home/ksenia/CLionProjects/vector)