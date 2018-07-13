cmake_minimum_required(VERSION 3.10)
project(NativeNodeModule)

set(CMAKE_JS_INC "/home/b1u3dr4g0nf1y/.cmake-js/node-x64/v9.9.0/include/node")
set(NODE_RUNTIME"node")
set(NODE_RUNTIMEVERSION "9.9.0")
set(NODE_ARCH "x64")
set(CMAKE_CXX_FLAGS="-std=c++11")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_JS_VERSION "3.7.3")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "/home/b1u3dr4g0nf1y/Documents/Dev/Projects/NativeNodeModule/build/Debug")

include_directories(${CMAKE_JS_INC})

file(GLOB SOURCE_FILES *.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})