package main

import (
	"fmt"
)

func main() {
	a := []int{0, 1, 2, 3, 4}
	for i := 0; i < len(a)+1; i++ {
		fmt.Println(a[i])
	}
}
