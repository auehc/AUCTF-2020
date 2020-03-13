#include "commandline.h"

// TODO: needs to be encrypted
char *network_info = "URL: ctf.auburn.edu, PORT: 68688";
char *creds = "bucky:let_m3_1n";

int main(int argc, char const *argv[])
{
    lp_input = input;

    char login[BUFSIZ];

    setvbuf(stdout, NULL, _IONBF, 0);

    printf("hello user\n");
    printf("Please Login: \n");
    printf("username: ");
    fgets(lp_input, BUFSIZ, stdin);
    remove_newline(lp_input);
    strcpy(login, lp_input);

    printf("password: ");
    fgets(lp_input, BUFSIZ, stdin);
    remove_newline(lp_input);
    sprintf(login, "%s:%s", login, lp_input);
    printf("%s\n", login);

    if (strcmp(login, creds))
    {
        printf("Error: Incorrect login credentials\n");
        exit(1);
    }
    commandline();
}
/*
 * Command line main loop.
 */
void *commandline()
{

    char *buffer;

    buffer = (char *)malloc(BUFSIZ * sizeof(char));
    if (buffer == NULL)
    {
        perror("Unable to malloc buffer");
        exit(1);
    }

    while (1)
    {
        printf("> [? for menu]: ");
        fgets(buffer, BUFSIZ, stdin);
        remove_newline(buffer);
        cmd_dispatch(buffer);
    }
    return (void *)NULL;
}
/*
 * Process a single command.
 */
int cmd_dispatch(char *cmd)
{
    char *args[MAXMENUARGS];
    int nargs = 0;
    char *word;

    int i, result;

    for (word = strtok(cmd, " ");
         word != NULL;
         word = strtok(NULL, " "))
    {
        if (nargs >= MAXMENUARGS)
        {
            printf("Command line has too many words\n");
            return E2BIG;
        }
        args[nargs++] = word;
    }

    if (nargs == 0)
    {
        return 0;
    }

    for (i = 0; cmdtable[i].name; i++)
    {
        if (*cmdtable[i].name && !strcmp(args[0], cmdtable[i].name))
        {
            assert(cmdtable[i].func != NULL);

            result = cmdtable[i].func(nargs, args);
            return result;
        }
    }

    printf("%s: Command not found\n", args[0]);
    return EINVAL;
}

/*
 * The quit command.
 */
int cmd_quit(int nargs, char **args)
{
    printf("Quiting AUBatch... \n");

    exit(0);
}

/*
 * Display menu information
 */
int cmd_helpmenu(int n, char **a)
{

    printf("\n");
    printf("AUbatch help menu\n");

    int i = 0;
    while (1)
    {
        if (helpmenu[i] == NULL)
        {
            break;
        }
        printf("%s\n", helpmenu[i]);
        i++;
    }
    printf("\n");
    return 0;
}

int cmd_read(int nargs, char **args)
{
    if (nargs != 2)
    {
        printf("Usage: read <filename>\n");
        return EINVAL;
    }
    print_file(args[1]);

    return 0;
}
