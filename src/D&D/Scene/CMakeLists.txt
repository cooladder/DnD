cmake_minimum_required(VERSION 3.12.1)

include_directories(${INCLUDE_DIR})
include_directories(${ROOT}/thirdparty)
include_directories(${ROOT}/ECS)

set(SCENE_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/gameplayScene.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/demoScene.cpp)

add_library(scene ${SCENE_SOURCE})