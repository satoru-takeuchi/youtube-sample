package main

import "syscall"

func main() {
	for i := 0; i < 10000000; i++ {
		_ = syscall.Getppid()
	}
}
