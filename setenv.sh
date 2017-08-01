#!/bin/bash

export BASEDIR=$PWD
export KERNEL=kernel7
export JOBS=$(nproc)

if [ $(uname -m) = "x86_64" ]; then
	export PATH=$PWD/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin:$PATH
else
	export PATH=$PWD/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin:$PATH
fi

