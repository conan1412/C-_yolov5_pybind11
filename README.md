# yolov5-onnxruntime

C++ YOLO v5 ONNX Runtime inference code for object detection.

## Dependecies:
- OpenCV 4.x
- ONNXRuntime 1.7+
- OS: Tested on Windows 10 and Ubuntu 20.04
- CUDA 11+ [Optional]

## Run
define your own include_paths and library_paths in makefile
```
make start <br/>
python test_yolo_pybind11.py
```