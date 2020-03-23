file = open("enc", "rb")

info = file.read()

out_file = open("s", "+wb")
for x in info:
    enc = (x ^ 78)
    if x is 0:
        enc = x
    out_file.write(enc.to_bytes(1, 'little'))
