all: build

test:
	./build/main.exe

build: build-init build/main.exe build/gen_random_floats.exe

build-init:
	mkdir -p ./build ./include

clean:
	rm -rf ./build ./include

build/main.exe: src/main.c include/data.h searches
	gcc src/main.c -o ./build/main.exe

build/gen_random_floats.exe: src/gen_random_floats.c
	gcc src/gen_random_floats.c -o ./build/gen_random_floats.exe

searches: include/naive.h include/branchless.h

include/naive.h: m4/naive.m4
	cd m4; m4 naive.m4 > ../include/naive.h

include/branchless.h: m4/common.m4 m4/branchless.m4
	cd m4; m4 branchless.m4 > ../include/branchless.h

include/data.h: m4/common.m4 m4/data.m4 build/gen_random_floats.exe
	cd m4/; m4 data.m4 > ../include/data.h


