cmake_minimum_required(VERSION 3.0.0)
project(yolo_ort)

set(ONNXRUNTIME_DIR /disk/223/person/huheng/tools/onnxruntime/onnxruntime/build/Linux/Release)
set(OpenCV_DIR /data/hh_workspace/opencv/opencv-4.5.4/build/installed/lib/cmake/opencv4)
find_package(OpenCV 4.5.4 REQUIRED)

include_directories("include/")

add_executable(yolo_ort
               src/main.cpp
               src/detector.cpp
               src/utils.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(yolo_ort PRIVATE "/disk/223/person/huheng/tools/onnxruntime/onnxruntime/include/onnxruntime/core/session" ${OpenCV_INCLUDE_DIRS})
target_compile_features(yolo_ort PRIVATE cxx_std_14)
target_link_libraries(yolo_ort ${OpenCV_LIBS})

if (UNIX)
    target_link_libraries(yolo_ort "/disk/223/person/huheng/tools/onnxruntime/onnxruntime/build/Linux/Release/libonnxruntime.so")
endif(UNIX)

