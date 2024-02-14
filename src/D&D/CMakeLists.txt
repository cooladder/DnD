cmake_minimum_required(VERSION 3.12.1)

include_directories(${INCLUDE_DIR})
include_directories(${ROOT}/thirdparty)

set(DND_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(LIB_SOURCE 
 ${ROOT}/thirdparty/imgui.cpp
 ${ROOT}/thirdparty/glad/glad.c
 ${ROOT}/thirdparty/imgui_demo.cpp
 ${ROOT}/thirdparty/imgui_draw.cpp
 ${ROOT}/thirdparty/imgui_impl_glfw.cpp
 ${ROOT}/thirdparty/imgui_impl_opengl3.cpp
 ${ROOT}/thirdparty/imgui_tables.cpp
 ${ROOT}/thirdparty/imgui_widgets.cpp)

add_subdirectory(Scene)
add_subdirectory(core)

add_library(window ${CMAKE_CURRENT_SOURCE_DIR}/window.cpp)
add_library(glfw3 ${ROOT}/lib/glfw3.dll)
add_library(lib ${LIB_SOURCE})

set_target_properties(glfw3 PROPERTIES LINKER_LANGUAGE C)