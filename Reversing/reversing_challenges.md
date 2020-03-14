# Reversing Challenge Descriptions

## Basic Crackme

Simple crackme program. Prompts users three times for different inputs. The first input is hardcoded in the binary,
the second is hard coded but backwards, and the third is obfuscated with an custom xor encryption.

## Encrypted Binary

Crackme that has been encrypted with an xor cipher. The first step is for the user to decode the binary so they can run it.
After that they have to crack the crackme.

## Resource Binary

Users are given a file with a resource binary packed into it. If they pull the binary out they can see it is spinning up a connection with a socket.
Unfortunately the flag is never received on the binaries side but can be recovered if using Wireshark.

There is a misdirection in the original file. It contains a crackme which can be solved but results in no flag.

## Intermediate Keygen 

Very basic keygen where it takes in a number performs some arbitrary calculations on it and then
forces it to fit within ASCII character 0x41 - 0x71

## Exception Flow Control 

Crackme that uses exception flow control to obscure where the program goes. (page 344 PBA)
Perhaps uses other things that break disassemblers

## Debug Trap Challenge

## x86 Assembly

Performs different mathematic operations that the user has to follow through. Will return a single number, that is the flag.

## Interpreted Language

Runs through different hashing algorithms and the user has to crack the hashes