cmake_minimum_required(VERSION 3.12.1)

set(INCLUDE_DIR ${ROOT}/include)

include_directories(${ROOT}/thirdparty)
include_directories(${INCLUDE_DIR})

add_subdirectory(D&D)
add_subdirectory(util)
add_subdirectory(renderer)

add_executable(main main.cpp)

target_link_libraries(main window)
target_link_libraries(main scene)
target_link_libraries(main core)
target_link_libraries(main renderer)
target_link_libraries(main util)

# target_link_libraries(main
#     -Wl,--start-group
#     scene 
#     window 
#     renderer
#     util
#     -Wl,--end-group
# )

target_link_libraries(main glfw3)
target_link_libraries(main lib)
target_link_libraries(main ${ROOT}/lib/libglfw3dll.a)
