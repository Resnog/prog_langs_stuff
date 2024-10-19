cmake_minimum_required(VERSION 3.25)

project(FunctionPtrs VERSION 1.0
    DESCRIPTION "Threads in C"
    LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_library(myThreads SHARED src/some_math_threads.c src/string_printing.c)
target_include_directories(myThreads PUBLIC inc)
#target_sources(funcptr PRIVATE inc/animal_p.h)

add_executable(thread_examples src/main.c )
target_link_libraries(thread_examples PUBLIC myThreads -pthreads)

add_custom_target(run
    COMMAND thread_examples 
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
