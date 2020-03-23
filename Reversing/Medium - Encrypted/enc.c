#include "enc.h"

int secret[] = {14, 5, 6, 26, 57, 125, 96, 117, 123, 84, 24, 106};

int seed[] = {97, 117, 99, 116, 102};

int encrypt()
{
    char password[BUFSIZ];

    printf("This file is password protected ... \nYou will have to enter the password to gain access\n");

    printf("Password: ");
    fgets(password, BUFSIZ, stdin);
    int *encrypted = malloc(sizeof(int) * strlen(password));
    for (int i = 0; i < strlen(password); i++)
    {
        int mod_i = i % 5;

        encrypted[i] = (int)password[i] ^ seed[mod_i];
        seed[mod_i] = encrypted[i];
    }

    int bad = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (secret[i] != encrypted[i])
            bad = 1;
    }
    return bad;
}

void print_file(char *filename)
{
    char flag[BUFSIZ];
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("That file doesn't exist chief\n");
        return;
    }
    if (!strcmp(filename, "flag.txt") && (encrypt()))
    {
        printf("Password Incorrect!\n");
        return;
    }

    fgets(flag, BUFSIZ, f);
    printf("%s", flag);
}

void remove_newline(char *buffer)
{
    int string_length = strlen(buffer);
    if (buffer[string_length - 1] == '\n')
    {
        buffer[string_length - 1] = '\0';
    }
}
