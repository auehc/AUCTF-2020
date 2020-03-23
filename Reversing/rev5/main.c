#include <stdio.h>
#include "commandline.h"
#include <stdio.h>
void print_t()
{
     char buffer[] = "flag.txt";
     char priv[] = "r";
     char error[] = "That file doesn't exist chief\n";
     char flag[BUFSIZ];
     char fmt[] = "%s";
     FILE *f;

     _asm {
          xor eax, eax
          jz valid
          jnz valid

          bad:
          call cleanup


          valid:
          and esp, 0xfffffff0


          lea eax, priv
          push eax
          lea eax, buffer
          push eax
          call fopen

          mov f, eax

          cmp f, 0
          jnz good
          push error
          call printf
          jmp cleanup

          good:

          mov eax, f
          push eax
          mov eax, BUFSIZ
          push eax
          lea eax, flag
          push eax
          call fgets

          lea eax,flag
          push eax
          lea eax, fmt
          push eax
          call printf


          cleanup:
          mov esp, [esp + 8]
          mov eax, fs : [0]
          mov eax, [eax]
          mov eax, [eax]
          mov fs : [0] , eax
          add esp, 8
          ret

     }
}

int main()
{
     _asm {
		push print_t
		push fs:[0]
		mov fs:[0], esp
     }

     printf("Welcome to my program!\n");

     printf("I've got a secret hidden within me!\nLet's see if you can find it!\n\n");

     printf("May main functionality is a calculator... unfortunately my programmer hasn't fleshed me out just yet!\n");

     commandline();
}
