1) Download linux and cross compiler:

$ ./update_env.sh

2) Set environment

$ source ./setenv.sh

3) Build kernel

$ make config
$ make kernel
$ make modules_install

4) Build test

$ cd test
$ make
