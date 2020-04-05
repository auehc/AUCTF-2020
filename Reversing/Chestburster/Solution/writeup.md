# Chestburster

## Solution

For this challenge intially we have to solve a custom cipher.
All it does is just swap your input characters around, and then at the end checks to see if it equals to `welcome_to_the_jungle!`.

There are a few ways to crack this. I would suggest using angr.

After solving the crackme you will get a hint to the next step!

This binary is compiled with a resource, the resource is another binary. You can use a lot of tools to extract resources but i recommend Resource Hacker.

Once this binary is pulled out you will get a Go binary. If you try to run it you will notice it wants an IP and a PORT for the command line argument.

So provide the one given by the hint that you received by solving the first step!
After running the binary you will see that it does not print the flag.

From here you can either go into the binary and see what's going on... or you can open Wireshark and sniff your traffic when you run the binary.
If you do that you can see that the flag is sent!
