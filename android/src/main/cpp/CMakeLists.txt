cmake_minimum_required(VERSION 3.5.1)

project(astronomicalAlgorithms CXX)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} 
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)

target_link_libraries(astronomicalAlgorithms aaplus aawrapper log)
