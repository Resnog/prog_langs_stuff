cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CPP_COMPILER clang+)

project(RasterCircle VERSION 1.0
                     DESCRIPTION "Draw nice raster circles"
                     LANGUAGES C)

add_library(rasterlib STATIC src/circle.c src/display.c src/point.c)
                # include/circle.h include/point.h include/display.h)
target_include_directories(rasterlib PUBLIC include)

add_executable(rasterCircle src/main.c)
target_link_libraries(rasterCircle PUBLIC rasterlib)

