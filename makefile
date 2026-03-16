all:
	mkdir -p build
	g++ src/globals.cpp src/window.cpp src/main.cpp src/input.cpp src/file.cpp -lncurses -o build/micro

run: all
	./build/micro src/main.cpp

clean:
	rm -rf build