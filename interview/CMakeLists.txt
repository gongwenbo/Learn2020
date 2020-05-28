cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g --std=c++11 -fdiagnostics-color=auto ")
include_directories(./src ./inc)
aux_source_directory(. MAIN)
add_subdirectory(./src)
add_executable(interview ${MAIN})
target_link_libraries(interview tencent -pthread)



