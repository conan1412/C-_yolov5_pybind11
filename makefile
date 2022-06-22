XX=g++ -O3 -Wall -shared -std=c++11 -fPIC
SRCS := $(shell find src -name "*.cpp")   # 查找src目录下所有的cpp文件
OBJS := $(SRCS:.cpp=.o)
OUTS := yolo_ort.cpython-36m-x86_64-linux-gnu.so

include_paths := ./include \
/disk/223/person/huheng/tools/onnxruntime/onnxruntime/include/onnxruntime/core/session \
/usr/include/python3.6m \
/disk/223/person/huheng/tools/pybind11/include
library_paths :=  /disk/223/person/huheng/tools/onnxruntime/onnxruntime/build/Linux/Release 
ld_librarys   := onnxruntime


run_paths     := $(library_paths:%=-Wl,-rpath=%)
include_paths := $(include_paths:%=-I%)
library_paths := $(library_paths:%=-L%)
ld_librarys   := $(ld_librarys:%=-l%)

link_flags := $(library_paths) $(ld_librarys) $(run_paths)


start:$(OBJS)
	$(XX) -o $(OUTS) $(OBJS) `pkg-config --cflags --libs opencv4` $(link_flags)
.cpp.o:
	$(XX) -o $@ -c $< `pkg-config --cflags --libs opencv4` $(include_paths)

clean:
	rm -rf $(OBJS) $(OUTS)
