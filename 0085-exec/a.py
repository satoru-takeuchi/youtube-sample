#!/usr/bin/python3

import os

print(f"プログラムA(exec前): pid={os.getpid()}")
os.execve("./b.py", ["b.py"],{})
print("この業は実行されないはず")
