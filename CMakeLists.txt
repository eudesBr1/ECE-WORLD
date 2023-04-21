cmake_minimum_required(VERSION 3.23)
project(ECE-WORLD C)

set(CMAKE_C_STANDARD 11)

add_executable(ECE-WORLD main.c)

target_link_libraries(ECE-WORLD -lmingw32 -lalleg44)
