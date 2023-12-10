ifneq ($(KERNELRELEASE),)
obj-m  := dm-dust.o

else
KDIR ?= /usr/src/linux-headers-$(shell uname -r)

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	rm -f *.o *.ko *.mod* Module.symvers modules.order
endif
