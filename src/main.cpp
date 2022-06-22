#include <iostream>
#include <opencv2/opencv.hpp>
#include <pybind11/pybind11.h>

#include "cmdline.h"
#include "utils.h"
#include "detector.h"

namespace py = pybind11;

int infer(std::string modelPath, std::string imagePath, std::string classNamesPath){
    const float confThreshold = 0.3f;
    const float iouThreshold = 0.4f;


    bool isGPU = true;
    const std::vector<std::string> classNames = utils::loadNames(classNamesPath);

    if (classNames.empty())
    {
        std::cerr << "Error: Empty class names file." << std::endl;
        return -1;
    }

    YOLODetector detector {nullptr};
    cv::Mat image;
    std::vector<Detection> result;

    try
    {
        detector = YOLODetector(modelPath, isGPU, cv::Size(640, 640));
        std::cout << "Model was initialized." << std::endl;

        image = cv::imread(imagePath);
        result = detector.detect(image, confThreshold, iouThreshold);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    utils::visualizeDetection(image, result, classNames);

    cv::imwrite("result.jpg", image);
    return 20;
}

PYBIND11_MODULE(yolo_ort, m){
    m.doc() = "pybind11 example yolov5 infer";
    m.def("infer", &infer, "example yolov5 infer", py::arg("modelPath")=1, py::arg("imagePath")=1, py::arg("classNamesPath")=1);
}
