cmake_minimum_required(VERSION 2.6)
add_definitions("-Wall -g -fdiagnostics-color=auto")
include_directories(./inc ./src)
link_directories(${CMAKE_SOURCE_DIR}/lib)
aux_source_directory(. TEST_ZOO)
add_subdirectory(./src)
add_executable(zoo ${TEST_ZOO})
target_link_libraries(zoo src zookeeper hashtable pthread)



