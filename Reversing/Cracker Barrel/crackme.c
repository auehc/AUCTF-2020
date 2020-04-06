#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGSIZE_MAX 256

int check();
int check_1(char *input);
int check_2(char *input);
int check_3(char *input);
void print_flag();

void remove_newline(char *buffer)
{
    int string_length = strlen(buffer);
    if (buffer[string_length - 1] == '\n')
    {
        buffer[string_length - 1] = '\0';
    }
}

int main(int argc, char const *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);

    if (check())
    {
        print_flag();
    }
    else
    {
        printf("That's not it!\n");
        return 0;
    }
    return 0;
}

int check()
{
    char input[BUFSIZ];
    char *lp_input = input;
    printf("Give me a key!\n");
    fgets(input, BUFSIZ, stdin);
    remove_newline(input);
    if (check_1(lp_input))
    {
        printf("You have passed the first test! Now I need another key!\n");
        fgets(lp_input, BUFSIZ, stdin);
        remove_newline(lp_input);
        if (check_2(lp_input))
        {
            printf("Nice work! You've passes the second test, we aren't done yet!\n");
            fgets(lp_input, BUFSIZ, stdin);
            remove_newline(lp_input);
            if (check_3(lp_input))
            {
                printf("Congrats you finished! Here is your flag!\n");
                return 1;
            }
        }
    }

    return 0;
}

int check_1(char *input)
{
    char *wars = "starwars";
    char *trek = "startrek";
    if (!strcmp(input, wars))
    {
        if (!strcmp(input, trek))
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

int check_2(char *input)
{
    //secret message this is
    char *buff = "si siht egassem terces";
    int len = strlen(input);

    char *tmp = malloc(sizeof(tmp) * (len + 1));
    for (int i = 0; i < len; i++)
    {
        tmp[i] = buff[(len - 1) - i];
    }

    if (strcmp(tmp, input))
    {
        return 0;
    }

    return 1;
}

int check_3(char *input)
{
    //l33t hax0r
    int secret[] = {122, 33, 33, 98, 54, 126, 119, 110, 38, 96};
    int *storage = malloc(strlen(input) * sizeof(int));
    for (int i = 0; i < strlen(input); i++)
    {
        storage[i] = ((int)(input[i]) + 2) ^ 20;
    }

    int bad = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (storage[i] != secret[i])
        {
            bad = 1;
        }
    }

    if (!bad)
    {
        return 1;
    }
    return 0;
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
