#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <string.h>

#define FLAG_SIZE 64


bool isInRoom1 = false;
bool isInRoom2 = false;
bool isInRoom3 = false;
bool isInRoom4 = false;
bool unlockHiddenRoom4 = false;
bool isInRoom = false;
bool key1 = false;
bool key2 = false;
char *key3 = "AAAAAAAAAAAAAAAA";
long long key4 = 0x0;

void starting_point();
void menu();
void game();
char get_input(char prompt[]);
void AAsDrwEk();
void get_key1(unsigned int arg_check);
void get_key2();
void set_key4();
void get_flag();
void room4();
void remove_newline(char *buffer);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    starting_point();
    game();
}

void game()
{
    while (true)
    {
        menu();
        char option = get_input("Your choice: ");
        printf("\n\n");
        if (option == '1')
        {
            printf("You can go into:\n Room 1\n Room 2\n Room 3\n Room 4\n\n");
        }
        else if (option == '2')
        {
            char room_number = get_input("Choose a room to enter: ");
            switch (room_number)
            {
            case '1':
                isInRoom1 = true;
                isInRoom2 = false;
                isInRoom3 = false;
                isInRoom4 = false;
                break;
            case '2':
                isInRoom1 = false;
                isInRoom2 = true;
                isInRoom3 = false;
                isInRoom4 = false;
                break;
            case '3':
                isInRoom1 = false;
                isInRoom2 = false;
                isInRoom3 = true;
                isInRoom4 = false;
                break;
            case '4':
                isInRoom1 = false;
                isInRoom2 = false;
                isInRoom3 = false;
                isInRoom4 = true;
                break;
            default:
                printf("Enter a proper room number!\n");
            }
        }
        else if (option == '3')
        {
            if (isInRoom1)
            {
                printf("Hello, this is just a plain old room. Poke around the others\n");
            }
            else if (isInRoom2)
            {
                printf("Hola como estas esta habitación es español\n");
            }
            else if (isInRoom3)
            {
                printf("Have you tried ALL the options?\n");
            }
            else if (isInRoom4)
            {
                room4();
            }
            else
            {
                printf("You aren't in a room!!\n");
            }
        }
        else if (option == '4')
        {
            printf("Wait a minute. This doesn't quit the program... Weird. Hey try entering 'Stephen' in Room 4. I heard the room's magic\n");
        }
        else
        {
            printf("You didn't enter a proper option. Try Again!\n");
        }
        printf("\n");
    }
}

void starting_point()
{
    printf("+------------------------+\n");
    printf("|          Welcome       |\n");
    printf("|            to          |\n");
    printf("|       the House of     |\n");
    printf("|          Madness       |\n");
    printf("+------------------------+\n");
    printf("Can you pwn the house?\n");
}

void menu()
{
    printf("1. List Rooms\n");
    printf("2. Enter Room\n");
    printf("3. Get Current Room Info\n");
    printf("4. Quit\n");
}

void room4()
{
    printf("Wow this room is special. It echoes back what you say!\n");
    while (true)
    {
        if (unlockHiddenRoom4)
        {
            printf("Welcome to the hidden room! Good Luck\n");
            char buf[16];
            printf("Enter something: ");
            gets(buf);
            break;
        }
        else
        {
            char buffer[16];
            printf("Press Q to exit: ");
            fgets(buffer, 16, stdin);
            remove_newline(buffer);
            printf("\tYou entered '%s'\n", buffer);
            if (strcmp(buffer, "Q") == 0)
            {
                break;
            }

            if (strcmp(buffer, "Stephen") == 0)
            {
                unlockHiddenRoom4 = true;
            }
        }
    }
}
char get_input(char prompt[])
{
    char choice[2];
    printf("%s", prompt);
    fgets(choice, 2, stdin);
    return choice[0];
}

void get_key1(unsigned int arg_check)
{
    if (!isInRoom && arg_check == 0xFEEDC0DE)
    {
        key1 = true;
    }
    else if (!isInRoom)
    {
        printf("Your very close to getting the key...solve one more riddle and the key is yours. Reverse the house\n");
    }
    else if (isInRoom)
    {
        printf("Haha this house is special.\n");
    }
    else
    {
        printf("Need to get the right keys. Reverse the house harder\n");
    }
}

void get_key2()
{
    if (!key1 && strcmp(key3, "Dormammu") == 0)
    {
        key2 = true;
    }
    else
    {
        printf("Need to get the right keys. Reverse the house harder\n");
    }
}

void AAsDrwEk()
{
    key3 = "Dormammu";
}

void set_key4()
{
    if (!isInRoom && key1 && key2 && strcmp(key3, "Dormammu") == 0)
    {
        key4 = 0x537472616e6765;
        __asm__("push %eax; mov 0x8(%ebp), %eax; mov %eax, 0x4(%ebp); pop %eax;");
    }
    else
    {
        printf("Need to get the right keys. Reverse the house harder\n");
    }
}

void get_flag()
{
    char flag[FLAG_SIZE];
    FILE *file;
    file = fopen("flag.txt", "r");
    if (file == NULL)
    {
        printf("'flag.txt' missing in the current directory!\n");
        exit(0);
    }

    if (key1 && key2 && strcmp(key3, "Dormammu") == 0 && key4 == 0x537472616e6765)
    {
        fgets(flag, sizeof(flag), file);
        printf("Damn you beat the house: %s\n", flag);
    }
    else if (key1 && key2 && strcmp(key3, "Dormammu") == 0)
    {
        printf("Surrender, Stephen. Surrender to the reverser");
    }
    else if (key1 && key2)
    {
        printf("You think you are ready? You are ready when the relic decides you are ready.\n");
    }
    else
    {
        printf("It's not going to be that easy. Come on");
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
