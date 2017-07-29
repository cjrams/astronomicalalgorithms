cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_library(aawrapper SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(aawrapper PUBLIC include/)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -Os")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Os")

target_link_libraries(aawrapper aaplus)
