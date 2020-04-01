file = open("purple_socks", "rb")

info = file.read()

out_file = open("dec", "+wb")
for x in info:
    enc = (x ^ 78)
    if x is 0 or x is 78:
        enc = x
    out_file.write(enc.to_bytes(1, 'little'))
