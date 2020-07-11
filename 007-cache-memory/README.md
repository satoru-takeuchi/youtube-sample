# Get the information of CPU0's cache memory

```console
ls /sys/devices/system/cpu/cpu0/cache
```

# Get the information of CPU0's cache memory n

```console
ls /sys/devices/system/cpu/cpu0/cache/index<n>
```

# Cache memory type: "Data", "Instruction", or "Unified(Data+Instruction)"

```console
cat /sys/devices/system/cpu/cpu0/index0/type
```
# Cache memory size

```console
cat /sys/devices/system/cpu/cpu0/index0/size
```

# The CPU list that share the same cache memory

```console
cat /sys/devices/system/cpu/cpu0/index0/shared_cpu_list
```
