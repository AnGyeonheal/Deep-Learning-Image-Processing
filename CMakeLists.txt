cmake_minimum_required(VERSION 3.25)
project(DLIP_GH)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

set(OpenCV_INCLUDE_DIRS ${OpenCV_INCLUDE_DIRS}/opencv2)

include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

file(COPY Image DESTINATION ${CMAKE_BINARY_DIR})

add_library(OpenCV STATIC Include/OpenCV_Setting.cpp)

include_directories(Include)
link_libraries(OpenCV)

add_subdirectory(Tutorial)
add_subdirectory(LAB)
