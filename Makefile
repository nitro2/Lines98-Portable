all:
	mkdir -p build
	cd build && cmake ../ && cmake --build .

run:
	ln -sf build/Lines98 ./Lines98
	./Lines98

clean:
	rm -rf build
