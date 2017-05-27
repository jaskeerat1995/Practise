obj-m := gpio.o
gpio-objs := init.o clean.o

all:
	make -C /lib/modules/3.8.13-bone65/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/3.8.13-bone65/build/ M=$(PWD) clean
