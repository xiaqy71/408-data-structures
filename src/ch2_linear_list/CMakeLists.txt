# src/ch2_linear_list/CMakeLists.txt
add_chapter_library(sqlist_core
    SOURCES
        sqlist.c
)

add_executable(linklist linklist.c)

target_include_directories(linklist
    PRIVATE
        ${DATASTRUCTURES_INCLUDE_DIR}
)