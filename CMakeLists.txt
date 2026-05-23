cmake_minimum_required(VERSION 3.10)
project(408DataStructures C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 统一输出到 build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 公共头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 逐章添加子目录
add_subdirectory(src/ch2_linear_list)
# ... 后续逐步添加