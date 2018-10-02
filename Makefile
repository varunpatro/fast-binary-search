all: build/bench.exe ./build/test.exe

test:
	./build/test.exe

bench:
	./build/bench.exe

clean:
	rm -rf ./build ./include

build/bench.exe: src/bench.c include/data.h include/naive.h include/naive_alt.h include/branchless.h include/cmov.h
	gcc -g -O3 src/bench.c -o ./build/bench.exe

build/test.exe: src/test.c include/data.h include/naive.h include/naive_alt.h include/branchless.h include/cmov.h
	gcc src/test.c -o ./build/test.exe

build/gen_random_floats.exe: src/gen_random_floats.c
	mkdir -p build;
	gcc src/gen_random_floats.c -o ./build/gen_random_floats.exe

include/naive.h: m4/naive.m4
	cd m4; m4 naive.m4 > ../include/naive.h

include/naive_alt.h: m4/naive_alt.m4
	cd m4; m4 naive_alt.m4 > ../include/naive_alt.h

include/cmov.h: m4/common.m4 m4/cmov.m4
	cd m4; m4 cmov.m4 > ../include/cmov.h

include/branchless.h: m4/common.m4 m4/branchless.m4
	cd m4; m4 branchless.m4 > ../include/branchless.h

include/data.h: m4/common.m4 m4/data.m4 build/gen_random_floats.exe
	mkdir -p include;
	cd m4/; m4 data.m4 > ../include/data.h
