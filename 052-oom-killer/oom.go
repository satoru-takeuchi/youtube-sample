package main

import (
	"fmt"
)

func main() {
	 a := make([]byte, 8*1024*1024*1024)
	 fmt.Println("MEMORY ALLOCATED")
	 for i := 0; i < len(a); i += 4096 {
		 a[i] = 1
	 }
}
