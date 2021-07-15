cmake_minimum_required(VERSION 3.17)
project(MultiCamerasCapture)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV)

add_executable(MultiCamerasCapture main.cpp MultiCamerasCapturer.cpp MultiCamerasCapturer.h)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
