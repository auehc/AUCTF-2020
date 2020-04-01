#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_flag();
void remove_newline(char *buffer);
int blah[] = {88, 65, 80, 82, 77, 88, 67, 83, 66, 67, 69, 68, 73, 83, 66, 86,
              88, 73, 83, 88, 87, 69, 82, 74, 82, 87, 83, 90, 65, 82, 83, 81};
char *encrypt(const char const *msg, const int a, const int b);
char *decrypt(const char const *cipher, const int a, const int b);
int inverse(const int a);
void get_string(char *buffer);
void DebuggerDetected();

void debugger_check()
{
    asm(".intel_syntax noprefix");
    // asm("mov ecx, 0x500");
    // asm("mov eax, 0xcc");
    // asm("call $+5");
    // asm("pop edi");
    // asm("sub edi, 5");
    // asm("repne scasb");
    // asm("jz DebuggerDetected");

    asm("mov ecx, 0x400;");
    asm("mov eax, 0xcc;");
    asm("call $+5");
    asm("pop edi;");
    asm("sub edi, 5;"); /* Get address and )size of block we want to check against breakpoint*/

    /* Loop trough the code looking for breakpoint */

    asm("antiBpLoop:");
    // Check if the opcode is 0xCC

    asm("cmp byte ptr[edi], al;");
    // asm("push edi");
    // asm("call printf");
    asm("jz DebuggerDetected;"); // Debugger detected!!

    asm("inc edi;");
    asm("dec ecx;");
    asm("jnz antiBpLoop;");
}

void DebuggerDetected()
{
    printf("BAD\n");
    exit(1);
}

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("54 68 65 20 6d 61 6e 20 69 6e 20 62 6c 61 63 6b 20 66 6c 65 64 20 \
    61 63 72 6f 73 73 20 74 68 65 20 64 65 73 65 72 74 2c 20 61 6e 64 20 74 68 \
    65 20 67 75 6e 73 6c 69 6e 67 65 72 20 66 6f 6c 6c 6f 77 65 64 2e\n");
    // char *msg = "IKILLWITHMYHEART";
    // char *mlsg = "SASRRWSXBIEBCMPX";
    debugger_check();
    const int a = 17;
    const int b = 12;
    printf("Input: ");
    char buf[BUFSIZ];
    fgets(buf, BUFSIZ, stdin);
    remove_newline(buf);

    char *cipherText = encrypt(buf, a, b);

    char *msg = calloc(sizeof(blah) / sizeof(int), sizeof(int));
    get_string(msg);

    if (strcmp(msg, cipherText) == 0)
    {
        print_flag();
    }
    else
    {
        printf("Not quite");
    }
    return 0;
}

void get_string(char *buffer)
{

    debugger_check();
    for (int j = 0, i = 0; i < (sizeof(blah) / sizeof(int)); i++)
    {
        if (i % 2 == 0)
        {
            buffer[((sizeof(blah) / sizeof(int)) / 2) - 1 - j] = (char)blah[i];
            j++;
        }
    }
}

void print_flag()
{
    debugger_check();
    char flag[BUFSIZ];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }
    fgets(flag, BUFSIZ, f);
    printf("%s", flag);
}
void remove_newline(char *buffer)
{
    debugger_check();
    int string_length = strlen(buffer);
    if (buffer[string_length - 1] == '\n')
    {
        buffer[string_length - 1] = '\0';
    }
}
char *encrypt(const char const *msg, const int a, const int b)
{
    debugger_check();
    ///Cipher Text initially empty
    char *cipher = calloc(strlen(msg), sizeof(char));
    for (int i = 0; i < strlen(msg); i++)
    {
        // Avoid space to be encrypted
        if (msg[i] != ' ')
            // ax * b mod 26
            cipher[i] =
                (char)((((a * (msg[i] - 'A')) + b) % 26) + 'A');
        else
        {
            cipher[i] = msg[i];
        }
    }
    return cipher;
}

char *decrypt(const char const *cipher, const int a, const int b)
{
    debugger_check();
    char *msg = calloc(strlen(cipher), sizeof(char));
    int a_inv = inverse(a);
    for (int i = 0; i < strlen(cipher); i++)
    {
        if (cipher[i] != ' ')
            // a^1 ( x - b) mod 26
            msg[i] =
                (char)(((a_inv * ((cipher[i] + 'A' - b)) % 26)) + 'A');
        else
        {

            msg[i] = cipher[i];
        }
    }

    return msg;
}

int inverse(const int a)
{
    debugger_check();
    int a_inv = 0;
    int flag = 0;

    //Find a^-1 (the multiplicative inverse of a
    //in the group of integers modulo m.)
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;

        //Check if (a*i)%26 == 1,
        //then i will be the multiplicative inverse of a
        if (flag == 1)
        {
            a_inv = i;
        }
    }

    return a_inv;
}
