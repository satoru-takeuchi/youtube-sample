package main

import (
	"fmt"
)

func main() {
	a := 1
	b := 2
	p := &a
	*p = 10
	p = &b
	*p = 20
	fmt.Printf("%d, %d\n", a, b)
}
