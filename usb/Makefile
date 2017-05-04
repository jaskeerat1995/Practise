INSTALLDIR= $(shell pwd)/modules
ifneq ($(KERNELRELEASE),)
	obj-m := vish_ch.o
	vish_ch-objs := usb_driver.o
else
KERNDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
		make -C $(KERNDIR) M=$(PWD) modules
		@rm -rf $(INSTALLDIR)
		@mkdir $(INSTALLDIR)
		@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
		rm -rf $(INSTALLDIR)

endif

