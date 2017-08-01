obj-m += hello.o

all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(BASEDIR)/linux M=$(PWD) modules
clean:
	make -C $(BASEDIR)/linux M=$(PWD) clean

