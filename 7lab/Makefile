.PHONY: build run tests clean

build:
	mkdir -p build
	cd ./build; cmake ..; make all

run:
	./build/*_exe

tests:
	./build/*_tests

clean:
	rm -rf ./build/