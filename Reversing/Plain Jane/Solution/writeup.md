# Plain Jane

## Solution

The intended solution was to get people to practice their assembly language skills.

This program calls three functions within main.
The first loops through a variable, j, set to 0 until it is less than 10.
Each iteration it performs (j + 10) * 25. It then adds that to an initial variable, i, which is originally set to 25.

We then return this variable but it is casted to an integer, it will return 0x42.

Within the second function we simply return 0xcf.

Within func_3 we look at the two passed parameters, here we past all the checks at the beginning.

At the end we set three variables, the first we can call i ORs the first param with the second. So we get `i = 0xcf`.
The second the second variable, j, is `AND`'d with the first and second param. So we get `j = 0x42`.
The third param, k, is `OR`'d with the first and second param; so we get `k = 0x8d`.

Next we loop `0xed` times. Each iteration we perform `i + (j - l)`. Where `l` is our loop variable.

At the end of this we will get `0x6fcf`.


## Alternate Solution

Compile the assembly and run it in GDB.

`gcc -c plain_jane.s -o plain.o`

`gcc plain.o -o plain`
