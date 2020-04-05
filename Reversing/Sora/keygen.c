#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGSIZE_MAX 256

// try_to_break_me
char *secret = "aQLpavpKQcCVpfcg";

int encrypt(char const *input);
void print_flag();

int main(int argc, char const *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);

    char input[30];
    char *lp_input = input;
    printf("Give me a key!\n");
    fgets(input, 30, stdin);
    if (encrypt(lp_input))
    {
        print_flag();
    }
    else
    {
        printf("That's not it!\n");
        return 1;
    }
    return 0;
}

int encrypt(char const *input)
{
    for (int i = 0; i < strlen(secret); i++)
    {
        // changing to int makes the assembly more readable
        int placeholder = (((((input[i] * 8) + 22) - 3) % 61) + 0x41);

        if (placeholder != secret[i])
        {
            return 0;
        }
    }

    return 1;
}

void print_flag()
{
    char flag[FLAGSIZE_MAX];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }
    fgets(flag, FLAGSIZE_MAX, f);
    printf("%s", flag);
}