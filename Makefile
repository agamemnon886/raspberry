
all: config kernel modules_install

config:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C linux bcm2709_defconfig

kernel:
	make -j$(JOBS) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C linux zImage modules dtbs

modules_install:
	mkdir $(BASEDIR)/modules
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C linux INSTALL_MOD_PATH=../modules modules_install


