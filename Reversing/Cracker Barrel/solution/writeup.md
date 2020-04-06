# Cracker Barrel

## Author's Solution

For this binary it runs three checks against user input.

First checks if user input is `starwars`
    hardcoded to check for starwars

Second check looks if user input is `secret message this is`
    converts user input to be backwards

Third check looks if the user input is `l33t hax0r`
    xor cipher with key of 20

## Alternate Solutions

Turns out there was an unintended solution thanks to user KERRO on discord.
Because I wrote bad code the second checks can be bypassed by simply entering an empty string.

This occurs because I loop through the string and set a bad flag if the string does not match. However, this flag is initially set to 0 so if you never loop through the for loop you can't ever set it to bad.
