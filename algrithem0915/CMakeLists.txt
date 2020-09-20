cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -std=c++11 -fdiagnostics-color=auto")
include_directories(./inc ./src)
add_subdirectory(./src)
aux_source_directory(./ MAIN )
add_executable(run ${MAIN})
target_link_libraries(run rank)




