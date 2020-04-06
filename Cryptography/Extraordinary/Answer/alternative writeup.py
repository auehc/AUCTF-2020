# On hitting the challenge server, one would see that if part of the flag is entered, an empty string is returned.

# > test
# b'\x15\x10\x10'
# > au
# b''
# > auctf{
# b''

# Thus, one could make a python script to work out the flag:

from pwn import *

r = remote('challenges.auctf.com', 30030)

# possible characters
possibleChars = 'abcdefghijklmnopqrstuvwxyz_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ{}!' #!#$%&()*+,-./:;<=>?@[\\]^_`{|}

flag = "au"

while flag[-1] != "}":
    for c in possibleChars:
        r.send(f'{flag}{c}\n')
        if r.recvline_contains(b'b') == b"> b''":
            flag += c
            print(flag)
            break

r.close()

# Output:
# auc
# auct
# auctf
# .
# .
# .
# auctf{n3v3R_r3Us3_y0uR_0Tp_872vc8972}
