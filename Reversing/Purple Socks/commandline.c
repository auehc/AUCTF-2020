#include "commandline.h"

char *network_info = "URL: challenges.auctf.com, PORT: 30049";
char *creds = "bucky:longing, rusted, seventeen, daybreak, furnace, nine, benign, homecoming, one, freight car";

int main(int argc, char const *argv[])
{
    lp_input = input;

    char login[BUFSIZ];
    char username[BUFSIZ];
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Please Login: \n");
    printf("username: ");
    fgets(lp_input, BUFSIZ, stdin);
    remove_newline(lp_input);
    strcpy(login, lp_input);
    strcpy(username, lp_input);
    printf("password: ");
    fgets(lp_input, BUFSIZ, stdin);
    remove_newline(lp_input);
    sprintf(login, "%s:%s", login, lp_input);

    if (strcmp(login, creds))
    {
        printf("Error: Incorrect login credentials\n");
        return 0;
    }
    printf("Welcome %s\n\n", username);
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
    printf("Quiting Terminal... \n");

    exit(0);
}

/*
 * Display menu information
 */
int cmd_helpmenu(int n, char **a)
{

    printf("\n");
    printf("Terminal help menu\n");

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

int cmd_list(int nargs, char **args)
{
    char *call = malloc(BUFSIZ * sizeof(char));
    for (int i = 0; i < nargs; i++)
    {
        printf("%s ", args[i]);
        strcat(call, args[i]);
        strcat(call, " ");
    }
    printf("\n");
    printf("call: %s \n", call);

    system(call);

    free(call);
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
