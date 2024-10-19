cmake_minimum_required(VERSION 3.25)

find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)

project(aProject VERSION 0.1
    DESCRIPTION "Insert your project name in C"
                     LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(libname SHARED src/tester.c)
target_include_directories(libname PUBLIC inc)

add_executable(test_stuff src/main.c)
target_link_libraries(test_stuff PUBLIC libname)

add_custom_target(run
    COMMAND test_stuff
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(say
    COMMAND echo "Hello world, I am alive!"
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(graphviz ALL
    COMMAND ${CMAKE_COMMAND} "--graphviz=foo.dot" .
    COMMAND dot -Tpng foo.dot -o foo.png
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

doxygen_add_docs(docs
    COMMENT "Docs for Stuff")
