# Easy - Encrypted

For this the challenge binary has been encrypted with an xor cipher.

First step is figuring out how to decrypt it.
Binary files start with magic bytes, so lets start by assuming this is an ELF file.

If we assume it is an ELF binary it will start with 0x7F 0x45 0x4c.
So to get those values we need to XOR the beginning of the encrypted file with these values.

So the first three bytes of `purple_socks` are 0x31 0x0b and 0x02.

If we XOR 0x31 with 0x7F we get `0x4e`.
If we XOR 0x0b with 0x45 we get `0x4e`.
If we XOR 0x02 with 0x4c we also get `0x4e`!

This is extremely unlikely if the binary is not an ELF file.
So our key must be `0x4e`!

So let's decrypt this binary.

```python

file = open("purple_socks", "rb")

info = file.read()

out_file = open("dec", "+wb")
for x in info:
    enc = (x ^ 78)
    if x is 0 or x is 78:
        enc = x
    out_file.write(enc.to_bytes(1, 'little'))

```

Note: I skip 0x00 bytes and 0x4e. If we look in the binary we see there are a lot of 0x00 bytes.
This is not uncommon for a binary file, however, if we were to xor this with 0x4e we would have a binary file filed with 0x4e.
Which is very unlikely.
Additionally if the author skipped 0x00 when encrypting we will also need to skip 0x4e when encrypting.
If we did not and we encrypted 0x4e with the key, 0x4e, the result would be zero.
The means when decrypting a 0x00 should either become 0x4e or stay 0x00, this is pretty hard to figure out so lets just skip 0x4e as well.

Once decrypted you will have to figure out how to login to the command prompt.
This can be found pretty easily it's just hardcoded as a plaintext string.

`username: bucky`
`password: longing, rusted, seventeen, daybreak, furnace, nine, benign, homecoming, one, freight car`

Once here you can open flag.txt but you need to recover the password

The password is XOR encrypted with a seed that is pulled from a hardcoded array

`open_sesame`
