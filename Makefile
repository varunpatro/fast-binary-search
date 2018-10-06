CC = gcc
all: build/bench.exe ./build/test.exe

test:
	./build/test.exe

bench:
	./build/bench.exe

clean:
	rm -rf ./build ./include

build/bench.exe: src/bench.c include/data.h include/naive.h include/naive_alt.h include/cmov.h include/branchless.h include/code_gen.h include/code_gen_ternary.h include/heap.h
	$(CC) -g -O3 src/bench.c -o ./build/bench.exe

build/test.exe: src/test.c include/data.h include/naive.h include/naive_alt.h include/cmov.h include/branchless.h include/code_gen.h include/code_gen_ternary.h include/heap.h
	$(CC) src/test.c -o ./build/test.exe

build/gen_random_floats.exe: src/gen_random_floats.c
	mkdir -p build;
	$(CC) src/gen_random_floats.c -o ./build/gen_random_floats.exe

include/data.h: build/gen_random_floats.exe m4/common.m4 m4/data.m4
	mkdir -p include;
	cd m4/; m4 data.m4 > ../include/data.h

include/naive.h: m4/naive.m4
	cd m4; m4 naive.m4 > ../include/naive.h

include/naive_alt.h: m4/naive_alt.m4
	cd m4; m4 naive_alt.m4 > ../include/naive_alt.h

include/cmov.h: m4/common.m4 m4/cmov.m4
	cd m4; m4 cmov.m4 > ../include/cmov.h

include/code_gen.h: m4/common.m4 m4/code_gen.m4
	cd m4; m4 code_gen.m4 > ../include/code_gen.h

include/code_gen_ternary.h: m4/common.m4 m4/code_gen_ternary.m4
	cd m4; m4 code_gen_ternary.m4 > ../include/code_gen_ternary.h

include/branchless.h: m4/common.m4 m4/branchless.m4
	cd m4; m4 branchless.m4 > ../include/branchless.h

build/gen_heap.exe: include/data.h src/gen_heap.c
	$(CC) src/gen_heap.c -o ./build/gen_heap.exe

include/heap_data.h: build/gen_heap.exe m4/common.m4 m4/heap_data.m4
	cd m4; m4 heap_data.m4 > ../include/heap_data.h

include/heap.h: include/heap_data.h m4/heap.m4
	cd m4; m4 heap.m4 > ../include/heap.h
