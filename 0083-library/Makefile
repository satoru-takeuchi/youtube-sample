.PHYONY: all
all: main-static main-dynamic

.DEFAULT_GOAL := all

libtest.so:test.c
	cc -c -fPIC -o libtest.o test.c
	cc -shared -o libtest.so libtest.o

libtest.a: test.c
	cc -c -o libtest.o test.c
	ar rcs libtest.a libtest.o

main.o: main.c
	cc -o main.o -c main.c

main-static: libtest.a main.o
	cc -o main-static main.o -static -L. -ltest

main-dynamic: libtest.so main.o
	cc -o main-dynamic main.o -L. -ltest -Wl,-rpath=.
