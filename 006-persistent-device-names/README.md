```console
lsblk
ls /sys/block
ls /sys/block/vda
cat /sys/block/vda/size
cat /sys/block/vda/removable
cat /etc/fstab
echo scratch1 >/dev/vdb # *** THIS COMMAND IS DANGEROUS ***
echo scratch2 >/dev/vdb # *** THIS COMMAND IS DANGEROUS ***
xxd -l 16 /dev/vdb
xxd -l 16 /dev/vdc
ls /dev/disk
ls -l /dev/disk/by-uuid
ls -l /dev/disk/by-label
ls -l /dev/disk/by-path
```
