cmake_minimum_required(VERSION 3.12)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++17" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}" )
set( CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -Os")
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Os")

add_subdirectory(src/main/cpp)
add_subdirectory(../aawrapper ${CMAKE_CURRENT_BINARY_DIR}/aawrapper EXCLUDE_FROM_ALL)
add_subdirectory(../../AA ${CMAKE_CURRENT_BINARY_DIR}/aaplus EXCLUDE_FROM_ALL)
