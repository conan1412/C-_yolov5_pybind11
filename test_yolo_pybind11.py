import yolo_ort
import sys
# modelPath, imagePath, classNamesPath = sys.argv[1], sys.argv[2], sys.argv[3]
modelPath, imagePath, classNamesPath = "models/yolov5m.onnx", "images/bus.jpg", "models/coco.names"
print(yolo_ort.infer(modelPath, imagePath, classNamesPath))