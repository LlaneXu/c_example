cmake_minimum_required(VERSION 3.12)
project(chain_stack C)

set(CMAKE_C_STANDARD 90)

#head file path
INCLUDE_DIRECTORIES(include)
#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(chain_stack main.c ${DIR_SRCS})