cmake_minimum_required(VERSION 3.10)
project(408DataStructures C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(DATASTRUCTURES_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(DATASTRUCTURES_RUNTIME_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)

# 统一输出到 build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DATASTRUCTURES_RUNTIME_OUTPUT_DIR})

include(CTest)

option(BUILD_EXAMPLES "Build example targets" ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(ModuleHelpers)

# 逐章添加子目录
add_subdirectory(src/ch2_linear_list)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()