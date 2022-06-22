# yolov5-onnxruntime-pybind11

pybind11 C++ YOLO v5 ONNX Runtime inference code for object detection.

## Dependecies:
- OpenCV 4.x
- ONNXRuntime 1.7+
- OS: Tested on Windows 10 and Ubuntu 20.04
- CUDA 11+ [Optional]
- pybind11

## Run
define your own include_paths and library_paths in makefile
```
make start
python test_yolo_pybind11.py
```