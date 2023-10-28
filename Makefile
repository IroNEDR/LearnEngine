BUILD_TYPE=Release

clean:
	mkdir build
	cd build && cmake ..
build:
	cmake --build ./build/ --config ${BUILD_TYPE}

.PHONY: clean build