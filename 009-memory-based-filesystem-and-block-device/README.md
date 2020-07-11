# memory-based filesystem: tmpfs

```console
mount -t tmpfs nodev mnt
mount | grep tmpfs | grep mnt
echo aaa mnt/test
cat mnt/aaa
umount mnt
mount -t tmpfs nodev mnt
ls mnt
```

# memory-based block device: brd

```console
modprobe brd
ls /dev/ram
parted /dev/ram0 p
mkfs.ext4 /dev/ram0
mount /dev/ram0 mnt
mount | grep ext4 | grep mnt
echo aaa mnt/test
cat mnt/test
umount mnt
mount /dev/ram0 mnt
ls mnt
umount mnt
modprobe -r brd
```
