cmake_minimum_required(VERSION 3.12.1)

include_directories(${INCLUDE_DIR})
include_directories(${ROOT}/thirdparty)

set(renderer ${CMAKE_CURRENT_SOURCE_DIR}/shader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Texture.cpp)

add_library(renderer ${renderer})