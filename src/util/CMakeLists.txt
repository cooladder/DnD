cmake_minimum_required(VERSION 3.12.1)

include_directories(${INCLUDE_DIR})
include_directories(${ROOT}/thirdparty)

set(UTIL ${CMAKE_CURRENT_SOURCE_DIR}/File.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/Camera.cpp)

add_library(util ${UTIL})
