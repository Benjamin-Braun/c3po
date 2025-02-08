CC=g++
IN=src/*.cpp src/rlimgui/*.cpp

compile:
	$(CC) $(IN) bin/icon.o -o bin/alpha -lraylib -lgdi32 -lwinmm

run:
	bin/alpha p911/scene.gltf

compile.run:
	$(CC) $(IN) bin/icon.o -o bin/alpha -lraylib -lgdi32 -lwinmm
	bin/alpha test.obj