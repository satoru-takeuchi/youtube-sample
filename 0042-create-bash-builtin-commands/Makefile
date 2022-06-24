BINARIES := hello myhello

.PHONY: all clean

all: hello myhello

myhello: myhello.c
	cc -L $@ -I/usr/include/bash/ -I/usr/include/bash/include -fpic -shared -o myhello.so myhello.c

clean:
	rm -rf *.o *.so *~ $(BINARIES)
