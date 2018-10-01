all: build/main.exe

test:
	./build/main.exe

clean:
	rm -rf ./build ./include

build/main.exe: src/main.c include/data.h include/naive.h include/branchless.h
	gcc src/main.c -o ./build/main.exe

build/gen_random_floats.exe: src/gen_random_floats.c
	mkdir -p build;
	gcc src/gen_random_floats.c -o ./build/gen_random_floats.exe

include/naive.h: m4/naive.m4
	cd m4; m4 naive.m4 > ../include/naive.h

include/branchless.h: m4/common.m4 m4/branchless.m4
	cd m4; m4 branchless.m4 > ../include/branchless.h

include/data.h: m4/common.m4 m4/data.m4 build/gen_random_floats.exe
	mkdir -p include;
	cd m4/; m4 data.m4 > ../include/data.h
