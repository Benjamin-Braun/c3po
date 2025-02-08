lib.linux:
	rm bin/*.o
	$(foreach file, $(wildcard rlimgui/*.cpp), g++ $(file) -c -o bin/$(shell basename $(file)).o -lraylib;)

compile.linux:
	g++ src/*.cpp bin/*.o -o bin/linux.x86_64 -lraylib

run.linux:
	bin/linux.x86_64 other/p911/scene.gltf

compile.run.linux:
	g++ src/*.cpp bin/*.o -o bin/linux.x86_64 -lraylib
	bin/linux.x86_64 other/test.obj

lib.win:
	rm bin/*.o
	$(foreach file, $(wildcard rlimgui/*.cpp), g++ $(file) -c -o bin/$(shell basename $(file)).o -lraylib -lgdi32 -lwinmm;)

compile.win:
	g++ src/*.cpp bin/*.o other/icon.o -o bin/win.exe -lraylib -lgdi32 -lwinmm

run.win:
	bin/win.exe other/p911/scene.gltf

compile.run.win:
	g++ src/*.cpp bin/*.o other/icon.o -o bin/win.exe -lraylib -lgdi32 -lwinmm
	bin/win.exe other/test.obj
