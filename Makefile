all: build test

build: build-init build/main.exe build/gen_random_floats.exe

build-init:
	mkdir -p ./build

clean:
	rm -r ./build

test:
	./build/main.exe

build/main.exe: src/main.c include/data.h searches
	gcc src/main.c -o ./build/main.exe

build/gen_random_floats.exe: src/gen_random_floats.c
	gcc src/gen_random_floats.c -o ./build/gen_random_floats.exe

searches: include/naive.h include/branchless.h

branchless.h: m4/branchless.m4
	m4 m4/branchless.m4 > include/branchless.h

data.h: m4/common.m4 m4/data.m4 build/gen_random_floats.exe
	m4 m4/data.m4 > include/data.h


