# stop-machine
A kernel module which stop system temporarily

# usage

Here is how to use this module on Ubuntu 22.04 and linux kernel 5.15.0-107-generic environment.

```
$ mkdir -p ~/src
$ cd ~/src
$ sudo apt install build-essential libncurses-dev bison flex libssl-dev libelf-dev linux-headers-$(uname -r)
$ git clone https://github.com/satoru-takeuchi/stop-machine.git
$ cd stop-machine
$ make
...
$ sudo insmod stop-machine.ko
$ 
```

Then entire system stop five second.

After that, you can uninstall this module like this.

```
$ sudo rmmod stop-machine
```
