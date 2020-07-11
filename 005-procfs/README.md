```console
ls /proc
cat /proc/$$/cmdline
ls /proc/$$/fd
echo hello >/proc/$$/fd/1
cat /proc/$$/stat
man 5 procfs
strace -o log.txt ps
dpkg -S /bin/ps
dpkg -L procps
```
