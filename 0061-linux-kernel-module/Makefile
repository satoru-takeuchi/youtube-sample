ifneq ($(KERNELRELEASE),)
obj-m  := hello.o bug.o

else
KDIR ?= /usr/src/linux-headers-$(shell uname -r)

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	rm -f *.o .ko *.mod*
endif
