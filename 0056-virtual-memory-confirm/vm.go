package main

import (
	"fmt"
	"os"
)

var foo int

func main() {
	pid := os.Getpid()
	fmt.Printf("%d: fooの値: %d, fooのアドレス: %x\n", pid, foo, &foo)
	fmt.Printf("%d: Enterキーを押してください:", pid) 
	fmt.Scanln()
	fmt.Printf("%d: fooの値: %d, fooのアドレス: %x\n", pid, foo, &foo)
	fmt.Printf("%d: Enterキーを押してください:", pid) 
	fmt.Scanln()
	fmt.Printf("%d: fooの値を書き換えます\n", pid)
	foo = 100
	fmt.Printf("%d: fooの値: %d, fooのアドレス: %x\n", pid, foo, &foo)
	fmt.Printf("%d: Enterキーを押してください:", pid) 
	fmt.Scanln()
}
