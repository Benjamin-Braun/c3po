compile.win:
	g++ src/*.cpp src/rlimgui/*.cpp bin/icon.o -o bin/win -lraylib -lgdi32 -lwinmm

run.win:
	bin/win.exe p911/scene.gltf

compile.run.win:
	g++ src/*.cpp src/rlimgui/*.cpp bin/icon.o -o bin/win -lraylib -lgdi32 -lwinmm
	bin/win.exe test.obj