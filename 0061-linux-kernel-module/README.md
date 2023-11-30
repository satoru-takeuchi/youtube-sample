# 環境

- OS: Ubuntu 22.04.3
- kernel: 5.15.0-89-generic

# 事前準備

```console 
$ sudo apt install build-essential libncurses-dev gawk flex bison openssl libssl-dev dkms libelf-dev libudev-dev libpci-dev libiberty-dev autoconf linux-headers-$(uname -r)
```

# ビルドとインストール

```console
$ make
$ sudo insmod hello.ko
$ sudo insmod bug.ko
```
