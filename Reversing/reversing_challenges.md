# Reversing Challenge Descriptions

## Basic Crackme

Simple crackme program. Prompts users three times for different inputs. The first input is hardcoded in the binary,
the second is hard coded but backwards, and the third is obfuscated with an custom xor encryption.

## Intermediate Keygen

Very basic keygen where it takes in a number performs some arbitrary calculations on it and then
forces it to fit within ASCII character 0x41 - 0x71

## Encrypted Binary

Crackme that has been encrypted with an xor cipher. The first step is for the user to decode the binary so they can run it.
After that they have to crack the crackme.

## Resource Binary

Users are given a file with a resource binary packed into it. If they pull the binary out they can see it is spinning up a connection with a socket.
Unfortunately the flag is never received on the binaries side but can be recovered if using Wireshark.

## Exception Flow Control

Crackme that uses exception flow control to obscure where the program goes. (page 344 PBA) 

## Debug Trap Challenge
