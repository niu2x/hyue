CORES := $(shell nproc)
JOBS := $(shell expr $(CORES) - 1)

build:
	cmake -S . -Bbuild -DCMAKE_BUILD_TYPE=Release -GNinja
	cmake --build build -j $(JOBS)
	cmake --install build --prefix dist
	nm -D dist/lib/libhyue.so|c++filt|grep " T "

.PHONY: build