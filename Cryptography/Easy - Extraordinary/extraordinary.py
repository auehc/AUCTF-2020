#Easy - Extraordinary
import random
import sys

simple_xor_flag = "auctf{n3v3R_r3Us3_y0uR_0Tp_872vc8972}"
SEED = 0
MIN_BYTE_SIZE = 0
MAX_BYTE_SIZE = 127

def xor(letter, key):
    xorred=0
    if type(letter) == int:
        xorred = key ^ letter
    else:
        xorred = key ^ ord(letter)
    return xorred

def encrypt(msg, seed):
    random.seed(seed)
    c = b''
    for letter in msg:
        rand_int = random.randint(MIN_BYTE_SIZE,MAX_BYTE_SIZE)
        y = xor(letter, rand_int)
        c += y.to_bytes((y.bit_length() + 7) // 8, byteorder='big')
    return c

def main():
    msg = input("> ")
    print(encrypt(msg, SEED))


if __name__ == "__main__":
    main()