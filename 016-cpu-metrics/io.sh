#!/bin/bash

for ((;;)) ; do
	taskset -c 0 dd if=/dev/zero of=test.img bs=1M count=1K oflag=direct 2>/dev/null
done
