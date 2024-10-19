cmake_minimum_required(VERSION 3.25)

project(FunctionPtrs VERSION 1.0
    DESCRIPTION "Function pointers for polymorphism in C"
                     LANGUAGES C)

add_library(funcptr SHARED src/animal.c src/cat.c src/duck.c)
target_include_directories(funcptr PUBLIC inc)
#target_sources(funcptr PRIVATE inc/animal_p.h)

add_executable(func_ptr src/main.c)
target_link_libraries(func_ptr PUBLIC funcptr)

