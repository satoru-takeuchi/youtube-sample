ifneq ($(KERNELRELEASE),)
obj-m  := dm-simple.o dm-hello.o

else
KDIR ?= /usr/src/linux-headers-$(shell uname -r)

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	rm -f *.o *.ko *.mod* Module.symvers modules.order
endif
