ARCH=sm_60
ifdef DEBUG
OPTFLAGS=-O0 -g -maxrregcount=128 -ccbin=g++ -std=c++11 -Xcompiler "-fPIC -g -O0 -fno-strict-aliasing" --use_fast_math -Xptxas "-dlcm=cg"
else
OPTFLAGS=-O3 -maxrregcount=128 -ccbin=g++ -std=c++11 -Xcompiler "-fPIC -fopenmp -O3 -fno-strict-aliasing" --use_fast_math -Xptxas "-dlcm=cg"
endif
.DEFAULT_GOAL := hhz
gold:
	nvcc hhz.driver.cpp out.cu -arch=$(ARCH) $(OPTFLAGS)
	./a.out
hhz:
	nvcc hhz.baked.cpp out.cu -arch=$(ARCH) $(OPTFLAGS)
