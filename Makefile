BUILD_TYPE=Debug

clean:
	rm -rf build
	mkdir build
	cd build && cmake .. -DCOMPILE_EXECUTABLE=ON -DCMAKE_BUILD_TYPE=${BUILD_TYPE}

build:
	cmake --build .