#!/usr/bin/python3

import os 
import sys

if len(sys.argv) < 2:
    print("usage: {} <pid>".format(sys.argv[0]), file=sys.stderr)
    os.exit(1)

pid = int(sys.argv[1])

os.waitpid(pid, 0)
