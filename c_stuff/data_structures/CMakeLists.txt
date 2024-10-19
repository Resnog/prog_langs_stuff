cmake_minimum_required(VERSION 3.25)

find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)

project(DataStructures VERSION 1.0
    DESCRIPTION "Data structures in C"
                     LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(datastruct SHARED src/linked_list.c)
target_include_directories(datastruct PUBLIC inc)

add_executable(test_data_structures src/main.c)
target_link_libraries(test_data_structures PUBLIC datastruct)

add_custom_target(run
    COMMAND test_data_structures
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(say
    COMMAND echo "taquito"
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(graphviz ALL
    COMMAND ${CMAKE_COMMAND} "--graphviz=foo.dot" .
    COMMAND dot -Tpng foo.dot -o foo.png
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

doxygen_add_docs(docs
                 COMMENT "Docs for Data Structs")
