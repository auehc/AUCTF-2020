#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
void get_flag()
{
    printf("yay!\n");
}

void vulnerable(char *arg)
{
    int *p;
    int a;
    __asm__("push %ebp; lea -0x1ff3(%ebx),%eax; push %eax; call printf");
    char buf[2048];

    strncpy(buf, arg, sizeof(buf) + 8);

    *p = a;
    printf("0x%x\n", a);
    printf("0x%x\n", __builtin_return_address(0));
}

int main()
{
    printf("get flag address 0x%x\n", &get_flag);
    char buf[BUFSIZ];
    fgets(buf, BUFSIZ, stdin);
    vulnerable(buf);

    return 0;
}
