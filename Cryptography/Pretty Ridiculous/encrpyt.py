# simple RSA encryptor

n = 627585038806247
e = 65537
d = 119987789848673
flag = 'auctf{R34lLy_Pr1M3s_w1L1_n3vEr_b3_thI5_Sm411_BuT_h3y}'
pub = (n,e)
priv = (n,d)

def main():
    print("message:", flag)
    print("public key:", pub)
    encrypted_msg = encrypt(flag, pub)
    decrypted_msg = decrypt(encrypted_msg, priv)
    print("encrypted message:", encrypted_msg)
    print("decrypted message:", decrypted_msg)

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