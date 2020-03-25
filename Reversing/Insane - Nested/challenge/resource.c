#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_flag();
int check();
void remove_newline(char *buffer);

int main()
{
    printf("Welcome to The Vault!\n\n\tThis challenge is simple answer the questions right and you get the flag!\n");

    printf("Be warned however, what you seek may not be here ... \n");
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

    // lmo_ewce_j!eo_tulgneht
    fgets(buffer, BUFSIZ, stdin);
    remove_newline(buffer);

    int size = (int)strlen(buffer);

    char *manip = calloc(size + 1, sizeof(char));
    if (manip == NULL)
    {
        printf("Error: out of memory\n");
        exit(1);
    }

    int j = 0;
    for (int i = j, k = 0; i < size; i += 2 + k)
    {
        if (i == 0)
        {
            continue;
        }
        manip[i] = buffer[j];
        j++;
        k++;
    }

    for (int i = 0, k = 0; i < size; i += 2 + k)
    {
        if (i == 0)
        {
            manip[i] = buffer[j];
            j++;
            i++;
            continue;
        }
        manip[i] = buffer[j];
        j++;
        k++;
    }

    for (int i = 1, k = 0; i < size; i += 3 + k)
    {
        if (i >= 7)
        {
            k++;
        }

        manip[i] = buffer[j];
        j++;
    }

    for (int i = strlen(buffer) - 3, count = 3, k = 0; j < strlen(buffer); i--, count--)
    {
        if (count == 0)
        {
            i -= 3;
            k++;
            count = (3 - k);
        }

        manip[i] = buffer[j];
        j++;
    }

    return strcmp(manip, "welcome_to_the_jungle!") == 0;
}

void print_flag()
{
    printf("Sorry Mario... you're flag is somewhere else\n");
}

void remove_newline(char *buffer)
{
    int string_length = (int)strlen(buffer);
    if (buffer[string_length - 1] == '\n')
    {
        buffer[string_length - 1] = '\0';
    }
}
