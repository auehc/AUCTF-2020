#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable();
void remove_newline(char *buffer);
void print_flag();

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Hi!\nWelcome to my program... it's a little buggy...\n");
    vulnerable();
}

void vulnerable()
{
    int x;
    int y;
    int w;
    int z;
    int a;
    char buffer[16];
    printf("Hey I heard you are searching for flags! Well I've got one. :)\n");
    printf("Here you can have part of it!\n");
    printf("auctf{\n");
    printf("\nSorry that's all I got!\n\n");

    x = 0;
    y = 10;
    w = 20;
    z = 20;
    a = 2;

    fgets(buffer, sizeof(buffer) + (5 * 4), stdin);

    if (x == 0x1337 && y < -20 && z != 20 && w == 0x667463 && a == 42)
    {
        print_flag();
    }
}

void remove_newline(char *buffer)
{
    int string_length = strlen(buffer);
    if (buffer[string_length - 1] == '\n')
    {
        buffer[string_length - 1] = '\0';
    }
}
void print_flag()
{
    char flag[BUFSIZ];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }

    printf("Wait... you aren't supposed to be here!!\n");
    fgets(flag, BUFSIZ, f);
    printf("%s", flag);
    exit(0);
}
