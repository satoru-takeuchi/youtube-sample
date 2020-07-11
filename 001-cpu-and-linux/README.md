# Show CPU information in the system

```console
cat /proc/cpuinfo
```
# Show the number of online CPUs in the system

```console
nproc
```

```console
grep -c processor /proc/cpuinfo
```

# Run program in a specific CPU

Run "./loop" in CPU 7.

```console
taskset -c 7 ./loop &
```

# CPU online/offline

```console
cat /sys/devices/system/cpu/cpu1/online
echo 0 >/sys/devices/system/cpu/cpu1/online # offline CPU1
echo 1 >/sys/devices/system/cpu/cpu1/online # oline CPU1 again
```
