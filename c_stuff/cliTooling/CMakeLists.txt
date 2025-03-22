cmake_minimum_required(VERSION 3.25)

# Doxygen support for API would be ideal
# but this is a small project
# find_package(Doxygen
#              OPTIONAL_COMPONENTS mscgen dia)

project(clitool VERSION 0.1
        DESCRIPTION "Console tools for learning"
        LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Main tool library
add_library(tools SHARED src/tools.c)
target_include_directories(tools PUBLIC inc)

# Unity test library
add_library(Unity STATIC Unity/src/unity.c)
target_include_directories(Unity PUBLIC
    Unity/src
)

add_executable(utest_cli src/utest.c)
target_link_libraries(utest_cli
    tools
    Unity
)

add_executable(clitool src/cli_tool.c)
target_link_libraries(clitool
    tools
)

add_custom_target(utest
    COMMAND utest_cli
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
