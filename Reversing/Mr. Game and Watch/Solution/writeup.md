# Mr. Game and Watch

## Solution

For this we are given a Java Class file.
We can use a Java Decompiler to retrieve essentially the source code.
I used the CFR, but you can also use Fernflower.

Once decompiled we can see that there is a function that runs three checks.

The first check performs a MD5 hash on user input and compares against a hard coded hash, `d5c67e2fc5f5f155dff8da4bdc914f41`.
If you through this hash into any online hash cracker or John the Ripper or Hashcat we can see the hash is `masterchief`.

The second check takes in a user input and hashes it with SHA1 and compares it against the built in hash.
However this time the hash it compares against is encrypted in the binary. However if we were to run this Java file we would see it is decrypted at run time, `264212deff89ade15661a59e7b632872d858f2c6`.
This hash is equivalent to `princesspeach`.

For our last check it grabs the users input and calculates a SHA-256 hash.
However, this time the users input is encrypted.
If we look at the encryption function we can see it is a simple XOR against a key.
The key for the third check is `313` which is compared against this array:

```268, 348, 347, 347, 269, 256, 348, 269, 256, 256, 344, 271, 271, 264, 266, 348, 257, 266, 267, 348, 269, 266, 266, 344, 267, 270, 267, 267, 348, 349, 349, 265, 349, 267, 256, 269, 270, 349, 268, 271, 351, 349, 347, 269, 349, 271, 257, 269, 344, 351, 265, 351, 265, 271, 346, 271, 266, 264, 351, 349, 351, 271, 266, 266 ```

If we decrypt this we can get this hash
`5ebb49e499a6613e832e433a2722edd0d2947d56fdb4d684af0f06c631fdf633`.

Which translates to `solidsnake`.

The 64 is a reference to Mario and Nintendo 64.

The 313 is a reference to Operation Intrude N313 for Metal Gear.
