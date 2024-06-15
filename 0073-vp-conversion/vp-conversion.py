#!/bin/python3

import os
import sys
import struct

def get_pagemap_entry(pid, vaddr):
    page_size = os.sysconf("SC_PAGE_SIZE")
    
    pagemap_file = f'/proc/{pid}/pagemap'
    
    offset = (vaddr // page_size) * 8
    
    with open(pagemap_file, 'rb') as f:
        f.seek(offset)
        buf = f.read(8)
        print(len(buf))
        entry = struct.unpack('Q', buf)[0]
        
        # see `man procfs`
        if entry & (1 << 63): # pesent bit
            pfn = entry & ((1 << 55) - 1) # page frame number
            physical_addr = pfn * page_size
            return physical_addr
        else:
            return None

if len(sys.argv) != 3:
    print('Usage: python3 aaa.py <pid> <vaddr>')
    sys.exit(1)

pid = int(sys.argv[1])
vaddr = int(sys.argv[2], 16)

paddr = get_pagemap_entry(pid, vaddr)
if paddr is not None:
    print(f'仮想アドレス {hex(vaddr)} は物理アドレス {hex(paddr)} にマップされています')
else:
    print(f'仮想アドレス {hex(vaddr)} は物理アドレスにマップされていません')
