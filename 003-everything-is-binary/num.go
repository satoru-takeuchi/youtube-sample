package main

import (
	"os"
	"bytes"
	"encoding/binary"
)

func main() {
	buf := new(bytes.Buffer)
	var num uint8
	num = 16
	err := binary.Write(buf, binary.LittleEndian, num)
	if err != nil {
		panic("failed to write a number")
	}
	os.Stdout.Write(buf.Bytes())
}
