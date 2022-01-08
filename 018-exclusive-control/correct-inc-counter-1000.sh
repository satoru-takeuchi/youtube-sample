#!/bin/bash

for ((i=0;i<1000;i++)) ; do
	flock lock ./inner-inc-counter.sh
done
