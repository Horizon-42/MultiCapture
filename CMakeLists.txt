cmake_minimum_required(VERSION 3.17)
project(MultiCamerasCapture)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

find_package(OpenCV)

add_executable(MultiCamerasCapture main.cpp MultiCamerasCapturer.cpp MultiCamerasCapturer.h)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
