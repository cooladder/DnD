cmake_minimum_required(VERSION 3.12.1)

include_directories(${INCLUDE_DIR})
include_directories(${ROOT}/thirdparty)
include_directories(${ROOT}/ECS)

set(CORE ${CMAKE_CURRENT_SOURCE_DIR}/DND_setup.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DND_build.cpp)

add_library(core ${CORE})