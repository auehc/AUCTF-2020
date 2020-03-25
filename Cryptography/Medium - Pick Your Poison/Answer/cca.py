#references:
# https://crypto.stackexchange.com/questions/18631/chosen-plaintext-attack-on-textbook-rsa-decryption
# applied cryptography, Schneier

import sys

n = 10221357148514336684111571397474179139093198252188953889343506516423709613718895061478720691981867849170787294195745723433520727656626277340717251893118927
e = 65537
d = 7904836439191611463715319357150636975842648583455833177098223664165575135933232094087493738937385495472344976450600376134806845564323099973819842116336705
flag = 'auctf{test}'
pub = (n,e)
priv = (n,d)

def main():
    print("message:", flag)
    print("public key:", pub)
    encrypted_msg = encrypt(flag, pub)
    decrypted_msg = decrypt(encrypted_msg, priv)
    print("encrypted message:", encrypted_msg)
    print("decrypted message:", decrypted_msg)

    r = 'e'
    r_inv = 2833643565924766605496277219101752632619896545161294147540774083761028407763654076449546330450418809671109348885949309466718617568173621440990921316904257
    print("r:", r)
    print("r^-1:", r_inv)
    print("r*r^-1 (mod n):", (ord(r)*r_inv) % n)

    encrypted_r = encrypt(r, pub)[0]
    modified_ciphertext = []
    for encrypted_letter in encrypted_msg:
        modified_ciphertext.append((encrypted_r * encrypted_letter) % n)
    print("modified_ciphertext:", modified_ciphertext)

    modified_plaintext = []
    for modified_value in modified_ciphertext:
        modified_plaintext.append(encrypt(modified_value, priv)[0])
    print("modified_plaintext:", modified_plaintext)

    plaintext = []
    for modified_plainvalue in modified_plaintext:
        plaintext.append((modified_plainvalue*r_inv) % n)
    message = ''
    for character in plaintext:
        message += chr(character)
    print("intercepted message:",message)

def encrypt(msg, key):
    n = key[0]
    e = key[1]
    ciphertext = []
    format = type(msg)
    if format == int:
        ciphertext.append(_encrypt_letter(msg, n, e))
    if format == str:
        for letter in msg:
            ciphertext.append(_encrypt_letter(letter, n, e))
    return ciphertext

def _encrypt_letter(letter, n, e):
    if type(letter) == int:
        return pow(letter, e, n)
    else:
        return pow(ord(letter), e, n)

def decrypt(ciphertext, priv_key):
    n=priv_key[0]
    d = priv_key[1]
    plaintext = []
    for letter in ciphertext:
        plaintext.append(_decrypt_letter(letter, n, d))
    return ''.join(plaintext)

def _decrypt_letter(letter, n, d):
    if type(letter) == int:
        return chr(pow(letter, d, n))
    else:
        return chr(pow(int(letter), d, n))

if __name__ == '__main__':
    main()