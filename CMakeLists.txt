cmake_minimum_required(VERSION 3.23)
project(ECE_WORLD C)

set(CMAKE_C_STANDARD 11)

add_executable(ECE_WORLD main.c)

target_link_libraries(ECE_WORLD -lmingw32 -lalleg44)
