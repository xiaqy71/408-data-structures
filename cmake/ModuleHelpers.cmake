function(add_chapter_library target)
    set(options)
    set(one_value_args)
    set(multi_value_args SOURCES)

    cmake_parse_arguments(ADD_CHAPTER_LIB
        "${options}"
        "${one_value_args}"
        "${multi_value_args}"
        ${ARGN}
    )

    add_library(${target} STATIC ${ADD_CHAPTER_LIB_SOURCES})
    target_include_directories(${target}
        PUBLIC
            ${DATASTRUCTURES_INCLUDE_DIR}
    )
endfunction()

function(add_example target source library)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE ${library})
    target_include_directories(${target}
        PRIVATE
            ${DATASTRUCTURES_INCLUDE_DIR}
    )
endfunction()

function(add_c_test target source library)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE ${library})
    target_include_directories(${target}
        PRIVATE
            ${DATASTRUCTURES_INCLUDE_DIR}
    )
    add_test(NAME ${target} COMMAND ${target})
endfunction()
