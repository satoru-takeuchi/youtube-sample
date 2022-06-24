#!/bin/bash

enable -f ./myhello.so myhello

echo "組み込みコマンド"
time (for ((i=0;i<10000;i++)) ; do
	myhello >/dev/null
done)

echo "実行ファイル"
time (for ((i=0;i<10000;i++)) ; do
	./hello >/dev/null
done)
