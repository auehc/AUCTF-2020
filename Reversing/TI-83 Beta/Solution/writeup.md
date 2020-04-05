# TI-83 Beta

## Solution

For this program it is a little tricky.
I originally wanted to force the users to cause an exception to get the flag, but then I also wanted to do some anti-dissassembly logic.
So I think this challenge was trying to do too much as once.
Regardless, at the beginning of the main function, before we print the welcome message we push a function to the stack.
The lines following this add this to the structured exception handler list.

We can solve this by two ways, causing an exception and forcing the function to run, or go to the function and pull the flag out ourselves.
The easiest way is to cause an exception. Since this is a calculator we may want to try to divide by 0 and hope there is not a check.

Turns out when you run `div 0 0` it performs float division, which allows division by zero.
If we look through the binary we can find a reference to `derr`, if we call this it does integer division.

By providing `derr 0 0` we will then get the flag!
