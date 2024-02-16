cmake_minimum_required(VERSION 3.12.1)
project(dnd)

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)

# copy the necessary
add_custom_target(copy
    COMMAND ${CMAKE_COMMAND} -P ${ROOT}/copy.cmake
)
add_dependencies(main copy)