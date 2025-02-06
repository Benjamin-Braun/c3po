build=$(cat "build")
cloc_output=$(cloc --json src | jq '.SUM.code')
builddate=$(date +"%Y-%m-%d %H:%M:%S")
printf "#pragma once\n#define VERSION \"0.0.1\"\n#define BUILD \"$build\"\n#define BUILD_DATE \"$builddate\"\n#define CODE_LINES \"$cloc_output\"">src/buildinfo.h
build=$((build+1))
printf "$build">build

for i in $(find ./rlimgui/ -name '*.cpp' -type f -print)
do
	echo "Compiling $i..."
	g++ $i -c -o bin/$(basename $i).o
done

echo "Compiling $cloc_output Lines..."
g++ $(find ./src/ -name '*.cpp') -c -o bin/main.o

ld $(find ./bin/ -name '*.o') -o ./alpha -lraylib

./alpha
