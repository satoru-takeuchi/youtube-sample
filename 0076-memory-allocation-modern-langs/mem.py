#!/usr/bin/env python3

import os

pid = os.getppid()

print('before memory allocation')
a = [0] * 128 * 1024 * 1024
print('after memory allocation')
