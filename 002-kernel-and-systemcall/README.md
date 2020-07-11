```console
cc -o hello_c hello_c.c
strace -o c.log ./hello_c
strace -o python.log ./hello_python
go build hello_go
strace -o go.log ./hello_go
```
