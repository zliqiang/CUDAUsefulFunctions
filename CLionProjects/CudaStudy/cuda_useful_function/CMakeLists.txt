cmake_minimum_required(VERSION 3.17)
project(cuda_useful_function CUDA)

set(CMAKE_CUDA_STANDARD 14)

file(GLOB SOURCES
        *.h
        *.cpp
        )

add_executable(cuda_useful_function main.cu ${SOURCE_FILE} ${SOURCES})

set_target_properties(
        cuda_useful_function
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)