#include <stdio.h>

void print_t() {

	printf("hi\n");
	_asm {
		
		mov esp, [esp+8]
		mov eax, fs:[0]
		mov eax, [eax]
		mov eax, [eax]
		mov fs:[0], eax
		add esp, 8
	}
	
}

int main() {
	_asm {
		push print_t
		push fs:[0]
		mov fs:[0], esp
		xor ecx, ecx
		div ecx
	}
	printf("Welcome to my program!\n");
	char buffer[BUFSIZ];
	fgets(buffer, BUFSIZ, stdin);

	if (strcmp(buffer, "secret") == 0) {
		printf("yay");
	}
}