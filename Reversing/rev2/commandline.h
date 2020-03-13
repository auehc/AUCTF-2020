#include "enc.h"

/* Error Code */
#define EINVAL 1
#define E2BIG 2

#define MAXMENUARGS 8
#define MAXCMDLINE 64

void menu_execute(char *line, int isargs);
int cmd_read(int nargs, char **args);
int cmd_quit(int nargs, char **args);
void showmenu();
int cmd_helpmenu(int n, char **a);
int cmd_dispatch(char *cmd);
void *commandline();

// char array of help definitions
static const char *helpmenu[] = {
    "help: Print help menu",
    "read <filename>: read filename",
    "quit: Exit Terminal",
    NULL};

typedef struct
{
    const char *name;
    int (*func)(int nargs, char **args);
} cmd;

// array of cmds to be used by the command line
static const cmd cmdtable[] = {
    {"?", cmd_helpmenu},
    {"h", cmd_helpmenu},
    {"help", cmd_helpmenu},
    {"q", cmd_quit},
    {"quit", cmd_quit},
    {"read", cmd_read},
    {"r", cmd_read},
    {NULL, NULL}};
void remove_newline(char *buffer);

char input[BUFSIZ];
char *lp_input;