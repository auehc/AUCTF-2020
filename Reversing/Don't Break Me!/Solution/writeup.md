# Don't Break Me!

This binary uses some anti-debugging tricks to stop the reversing process.
At the beginning of each function we call a checker.
This checker will scan essentially the entire binary for `0xcc` bytes.

`0xcc` is used by debuggers to stop a binary from executing, it is a breakpoint.
Therefore, if you try to use software breakpoints the binary will exit!

There are a few ways around this.
You can use hardware breakpoints, or you can patch out the calls to the anti-debugger check.

At the end of the day the binary is using an affine cipher to encrypt and decrypt input.
Therefore, you must provide an input that encrypts to the hardcoded ciphertext.

However, this is one additional step after the affine cipher.
The encrypted cipher text has garbage values in the array.
We see that after it encrypts our input we call a function that takes the hardcoded cipher text.
Here we loop through it and every even value we pull out into a new array and put it in backwards.

Now we have our hardcoded array. If we decode using an affine cipher we can get IKILLWITHMYHEART.

## Reference

At the beginning we print a long string of numbers. If we convert this to ascii we get `The man in black fled across the desert, and the gunslinger followed.`
This is a reference to the Dark Tower series as `IKILLWITHMYHEART` is also a reference.
