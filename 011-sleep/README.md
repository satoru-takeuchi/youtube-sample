```console
time sleep 1
man sleep
strace -o log.txt sleep 1
less log.txt
man nanosleep
for ((i=0;i<1000;i++)) ; do taskset -c 0 ./loop.sh & done
time taskset -c 0 sleep 1
```
