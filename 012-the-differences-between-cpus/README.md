```console
go build -o test-x86_64 test.go
GOARCH=arm go build -o test-arm test.go
file test-x86_64
file test-arm
./test-x86_64
./test-arm
objdump -d test-x86_64
arm-linux-gnueabi-objdump -d test-arm
less /proc/cpuinfo
```
