package main

import (
	"fmt"
	"sync"
)

const NLOOP = 10000000000

func main() {
	var wg sync.WaitGroup
	for i := 0; i < 2; i++ {
		wg.Add(1)
		go func(id int) {
			for j := 0; j < NLOOP; j++ {
			}
			fmt.Printf("%d has been completed\n", id)
			wg.Done()
		}(i)
	}
	wg.Wait()
}
