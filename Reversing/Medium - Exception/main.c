#include <stdio.h>
#include "commandline.h"
#include <stdio.h>
void print_t()
{
     _asm {
		xor eax,eax
		jz valid
		__asm __emit(0xea)
          pop eax 


		valid:
		mov eax, 0
          sub esp, 0x20
          mov [esp], 'a'
          mov [esp+1], 'u'
          mov [esp+2], 'c'
          mov [esp+3], 't'
          mov [esp+4], 'f'
          mov [esp+5], '{'
          mov [esp+6], 'o'
          xor eax, eax
          jz valid2
          __asm __emit(0xea)
          pop eax

          valid2:
          mov [esp+7], 'o'
          mov [esp+8], 'p'
          mov [esp+9], 's'
          mov [esp+10], '_'
          mov [esp+11], 'd'
          mov [esp+12], 'i'
          mov [esp+13], 'd'
          mov [esp+14], '_'
          mov [esp+15], 'i'
          mov [esp+16], '_'
          mov [esp+17], 'd'
          mov [esp+18], 'o'
          mov [esp+19], '_'
          mov [esp+20], 't'
          mov [esp+21], 'h'
          mov [esp+22], 't'
          mov [esp+23], '}'
          mov [esp+24], '\n'
          mov [esp+25], 0x0
          push esp
          call printf

          mov esp, [esp + 8]
          mov eax, fs : [0]
          mov eax, [eax]
          mov eax, [eax]
          mov fs : [0], eax
          add esp, 8
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
