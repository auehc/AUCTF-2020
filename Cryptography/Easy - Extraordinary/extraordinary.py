#Easy - Extraordinary
import sys

OTP = [97, 117, 99, 116, 102, 123, 110, 51, 118, 51, 82, 95, 114, 51, 85, 115, 51, 95, 121, 48, 117, 82, 95, 48, 84, 112, 95, 56, 55, 50, 118, 99, 56, 57, 55, 50, 125]

def xor(letter, key):
    xorred=0
    if type(letter) == int:
        xorred = key ^ letter
    else:
        xorred = key ^ ord(letter)
    return xorred

def encrypt(msg, seed=None):
    c = b''
    key_index = 0
    for letter in msg:
        y = xor(letter, OTP[(key_index % len(OTP))])
        c += y.to_bytes((y.bit_length() + 7) // 8, byteorder='big')
        key_index += 1
    return c

def main():
    msg = input("> ")
    print(encrypt(msg))


if __name__ == "__main__":
    main()