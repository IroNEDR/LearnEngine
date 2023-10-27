BUILD_TYPE=Debug

clean:
	mkdir build
	cd build && cmake .. -DCOMPILE_EXECUTABLE=ON -DCMAKE_BUILD_TYPE=${BUILD_TYPE}

build:
	cmake --build ./build/ --config ${BUILD_TYPE}

.PHONY: clean build