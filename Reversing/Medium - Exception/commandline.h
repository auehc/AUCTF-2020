#include <stdlib.h>
#include <stdio.h>

/* Error Code */
#define EINVAL 1
#define E2BIG 2

#define MAXMENUARGS 8
#define MAXCMDLINE 64

#define TODO "!! Under construction !!\n"

int cmd_dispatch(char* cmd);
int cmd_quit(int nargs, char **args);
int cmd_helpmenu(int n, char **a);
int cmd_subtract(int n, char** a);
int cmd_add(int n, char** a);
int cmd_divide(int n, char** a);
int cmd_multiply(int n, char** a);
int cmd_mul_secret(int n, char** a);
int cmd_div_secret(int n, char** a);

void *commandline();

// char array of help definitions
static const char *helpmenu[] = {
    "help: Print help menu",
    "+ | add [arg2, arg3, ..., argN] : Add args",
    "- | sub [arg2, arg3, ..., argN] : Sub args",
    "* | mul [arg2, arg3, ..., argN] : Multiply args",
    "/ | div [arg2, arg3, ..., argN] : Divide args",
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
    {"+", cmd_add},
    {"-", cmd_subtract},
    {"add", cmd_add},
    {"addition", cmd_add},
    {"sub", cmd_subtract},
    {"subtract", cmd_subtract},
     {"*", cmd_multiply},
    {"/", cmd_divide},
    {"mul", cmd_multiply},
    {"div", cmd_divide},
    {"multiply", cmd_multiply},
    {"divide", cmd_divide},
    {"merr", cmd_mul_secret},
    {"derr", cmd_div_secret},
    {NULL, NULL}};
void remove_newline(char *buffer);

char input[BUFSIZ];
char *lp_input;