.PHONY: all clean

KERNEL_VERSION := 5.15.0-107-generic
SRCDIR := /lib/modules/$(KERNEL_VERSION)/build

obj-m += stop-machine.o

all:
	make -C $(SRCDIR) M=$(PWD) modules

clean:
	make -C $(SRCDIR) M=$(PWD) clean
