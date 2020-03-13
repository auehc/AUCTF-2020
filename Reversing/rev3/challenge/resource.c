#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_flag();
int check();
void remove_newline(char *buffer);

int main()
{
    printf("Welcome to The Vault!\n\n\tThis challenge is simple answer the questions right and you get the flag!\n");

    printf("\tI have to warn you thought.... you are looking in the wrong place\n");

    printf("\n\n\tWell ... if you are still here lets start! Just don't get mad at me when you waste your time!\n");

    if (check() == 1)
    {
        printf("\tNice job!\n");
        print_flag();
    }
    else
    {
        printf("\tThat is not correct\n");
    }
}

int check()
{
    printf("\tYou know the drill, give me some input and I'll tell you if it's right\n");
    printf("\n\t");
    char buffer[BUFSIZ];
    fgets(buffer, BUFSIZ, stdin);
    remove_newline(buffer);

    int size = (int) strlen(buffer);

    char *manip = malloc(size * sizeof(char));

    int j = 0;
    for (int i = 0, k = 0; i < size; i += 2 + k)
    {
        if (i == 0)
        {
            continue;
        }
        manip[i] = buffer[j];
        j++;
        k++;
    }

    for (int i = j + 1; i >= 0; i -= 3)
    {
        if (i > size)
        {
            continue;
        }
        manip[i] = buffer[j];
        j++;
    }

    for (int i = j - 3; i < size; i += 3)
    {
        if (i < 0)
        {
            continue;
        }
        manip[i] = buffer[j];
        j++;
    }

    return strcmp(manip, "hello!") == 0;
}

void print_flag()
{
    char flag[BUFSIZ];
    FILE* f;
    fopen_s(&f, "flag.txt", "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }
    fgets(flag, BUFSIZ, f);
    printf("\n\tflag: %s", flag);
}

void remove_newline(char *buffer)
{
    int string_length = (int)strlen(buffer);
    if (buffer[string_length - 1] == '\n')
    {
        buffer[string_length - 1] = '\0';
    }
}