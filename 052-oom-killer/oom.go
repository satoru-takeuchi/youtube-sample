package main

func main() {
	 a := make([]byte, 8*1024*1024*1024)
	 for i := 0; i < len(a); i += 4096 {
		 a[i] = 1
	 }
}
