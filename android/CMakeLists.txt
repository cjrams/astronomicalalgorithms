cmake_minimum_required(VERSION 2.8)

project(astronomicalAlgorithms CXX)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}" )

add_subdirectory(src/main/cpp)
add_subdirectory(../aawrapper ${CMAKE_CURRENT_BINARY_DIR}/aawrapper EXCLUDE_FROM_ALL)
add_subdirectory(../../AA ${CMAKE_CURRENT_BINARY_DIR}/aaplus EXCLUDE_FROM_ALL)
