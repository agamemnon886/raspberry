#!/bin/bash

if [ -d linux ]; then
	cd linux
	git pull
	cd ..
else
	git clone --depth=1 https://github.com/raspberrypi/linux
fi

if [ -d tools ]; then
	cd tools
	git pull
	cd ..
else
	git clone https://github.com/raspberrypi/tools
fi

