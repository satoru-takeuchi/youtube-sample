package main

import "sync"

func loop() {
	for i := 0; i < 10000000000; i++ {
	}
}
func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		loop()
		wg.Done()
	}()
	loop()
	wg.Wait()
}
