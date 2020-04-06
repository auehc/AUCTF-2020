Fahrenheit 451
--

Open pacp file in Wireshark then Export Objects > SMB

Save the PDF File

Flag is hidden in white text with a substitution cipher.
You should try and CTRL+F { or } as the flag format is auctf{}.
That didn't work as ROT1-25 wouldn't change the brackets.
Alternatively you can CTRL-A the whole text and look for anything out of place and then identify the cipher.

You should then try ROT47.
ROT47 uses a larger set of characters from the common character encoding known as ASCII

Alot of people ended up with this. ```auctf{burn_the_books\x7f\x7f\x8f\x7f}```
If you use python and an ascii table you can do ```int('7f',16)``` and ```int('8f',16)``` and find that it turns out to be 127 and 143.

127 - 47*2 = 33 and 33 == !

143 - 47*2 = 49 and 49 == 1

https://upload.wikimedia.org/wikipedia/commons/thumb/d/dd/ASCII-Table.svg/738px-ASCII-Table.svg.png

Check out this lookup table from https://rot47.net/: 
```
'!"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~', 
'PQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~!"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO'
```
```ROT47: 2F4E7L3FC?0E9603@@<DPP`PN```


[Marshmallow's](https://github.com/xiongnemo) implementation in python:

```
after = """!"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"""
origin = """PQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~!"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO"""
ciper_text = "2F4E7L3FC?0E9603@@<DPP`PN"
decoded = ""
for char in ciper_text:
    decoded = decoded + after[origin.index(char)]
print(decoded)
```

Decoded in CyberChef: https://gchq.github.io/CyberChef/#recipe=ROT47(47)&input=MkY0RTdMM0ZDPzBFOTYwM0BAPERQUGBQTg


Flag: auctf{burn_the_books!!1!}
