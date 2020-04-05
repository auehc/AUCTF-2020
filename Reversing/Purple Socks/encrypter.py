file = open("enc.out", "rb")

info = file.read()

out_file = open("purple_socks", "+wb")
for x in info:
    enc = (x ^ 78)
    if x == 0 or x == 78:
        enc = x
    out_file.write(enc.to_bytes(1, 'little'))
