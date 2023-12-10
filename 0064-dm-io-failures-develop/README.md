# 環境

- OS: Ubuntu 22.04.3
- kernel: 5.15.0-89-generic

# 事前準備

```console 
$ sudo apt-get install e2fsprogs xfsprogs libncurses-dev gawk flex bison openssl libssl-dev dkms libelf-dev libudev-dev libpci-dev libiberty-dev autoconf llvm dmsetup linux-headers-$(uname -r)
$ git clone https://github.com/satoru-takeuchi/youtube-sample
$ cd youtube-sample/0064-dm-io-failures-develop
$ dd if=/dev/zero of=test.img bs=1 count=0 seek=1GiB
$ sudo losetup /dev/loop0 test.img # /dev/loop0が既に使われていた場合は/dev/loop1など番号を増やして試して、後の記述は読み替えてください
```

# ビルドとインストール

```console
$ make -C kernel-modules
$ sudo insmod kernel-modules/dm-simple.ko
$ sudo insmod kernel-modules/dm-hello.ko
```
