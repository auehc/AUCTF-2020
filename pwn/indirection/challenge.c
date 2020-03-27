#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

// #define DEBUG
// gcc -o challenge challenge.c -fno-stack-protector -z execstack -m32

/* Error Code */
#define EINVAL 1
#define E2BIG 2

#define MAXMENUARGS 8
#define MAXCMDLINE 64
typedef struct
{
    const char *name;
    int (*func)(int nargs, char **args);
} cmd;

typedef struct
{
    const char *class;
    int skill;
    int grade;
    int tests[BUFSIZ];
    int total_tests;
} knowledge;

void menu_execute(char *line, int isargs);
int cmd_attend(int nargs, char **args);
int cmd_quit(int nargs, char **args);
void showmenu();
int cmd_helpmenu(int n, char **a);
int cmd_dispatch(char *cmdinput, const cmd *table);
int cmd_list(int n, char **a);
int cmd_study(int n, char **a);
int cmd_stats(int n, char **a);
int cmd_grades(int n, char **a);
void pick_activity(int class_index);
int class_algebra(int n, char **a);
int class_compsci(int n, char **a);
int class_hacker(int n, char **a);
void *commandline();
void learn(int class_index);
void take_test(int class_index);

// char array of help definitions
static const char *helpmenu[] = {
    "help: Print help menu",
    "attend <class>: go to class",
    "study <class>: study for class",
    "list: list classes",
    "stats: check stats",
    "grades: check grades",
    "quit: Exit Terminal",
    NULL};

// array of cmds to be used by the command line
static const cmd cmdtable[] = {
    {"?", cmd_helpmenu},
    {"h", cmd_helpmenu},
    {"help", cmd_helpmenu},
    {"q", cmd_quit},
    {"quit", cmd_quit},
    {"study", cmd_study},
    {"s", cmd_study},
    {"attend", cmd_attend},
    {"a", cmd_attend},
    {"ls", cmd_list},
    {"list", cmd_list},
    {"stats", cmd_stats},
    {"grades", cmd_grades},
    {NULL, NULL}};

static knowledge brain[] = {
    {"Algebra", 0, 100, {0}, 0},
    {"CompSci", 0, 100, {0}, 0},
    {NULL, 0, 0, {0}, 0}};

static const cmd classtable[] = {
    {"Algebra", class_algebra},
    {"CompSci", class_compsci},
    {"Hacker", class_hacker},
    {NULL, NULL}};

void remove_newline(char *buffer);

char input[BUFSIZ];
char *lp_input;

void print_flag()
{
    char flag[BUFSIZ];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }
    fgets(flag, BUFSIZ, f);
    printf("%s", flag);
    exit(0);
}

void class()
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
        printf("What should we do?\n");
        printf("> [? for menu]: ");
        fgets(buffer, BUFSIZ, stdin);
        remove_newline(buffer);
        cmd_dispatch(buffer, cmdtable);
    }
    return;
}

int cmd_dispatch(char *cmdinput, const cmd *table)
{
    char *args[MAXMENUARGS];
    int nargs = 0;
    char *word;

    int i, result;

    for (word = strtok(cmdinput, " ");
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

    for (i = 0; table[i].name; i++)
    {

        if (*table[i].name && !strcmp(args[0], table[i].name))
        {
            assert(table[i].func != NULL);

            result = table[i].func(nargs, args);
            return result;
        }
    }

    printf("%s: Command not found\n", args[0]);
    return EINVAL;
}

void test(char *arg)
{

    int *p;
    int a;

#ifdef DEBUG
    __asm__("push %ebp; lea -0x1e2b(%ebx),%eax; push %eax; call printf");
#endif
    char buf[2048];
    strncpy(buf, arg, sizeof(buf) + 8);

    *p = a;
#ifdef DEBUG
    printf("0x%x\n", a);
#endif
}

int main()
{
    printf("Welcome to your new online class!");
    printf("We here, at Eon Pillars, we think Zoom is trash and prefer to have our lessions via command line!\n");

    printf("May I get your name?\n\tName: ");
    char buf[BUFSIZ];
    fgets(buf, BUFSIZ, stdin);
    remove_newline(buf);

    printf("Thanks! It is nice to meet you %s!\n\n", buf);
    // sleep(1);
    printf("Well enough of that let's start class ... ");

    class();

    return 0;
}

int cmd_list(int nargs, char **args)
{
    printf("You have these classes:\n");
    for (int i = 0; classtable[i + 1].name; i++)
    {
        printf("\t%s\n", classtable[i].name);
    }
}

int cmd_attend(int nargs, char **args)
{
    char *call = malloc(sizeof(args));
    for (int i = 1; i < nargs; i++)
    {
        strcat(call, args[i]);
        strcat(call, " ");
    }
    cmd_dispatch(call, classtable);
    free(call);
}

int cmd_quit(int nargs, char **args)
{
    printf("Quiting Terminal... \n");

    exit(0);
}

int cmd_study(int nargs, char **args)
{
    char *call = malloc(sizeof(args));
    for (int i = 1; i < nargs; i++)
    {
        strcat(call, args[i]);
        strcat(call, " ");
    }
    for (int i = 0; classtable[i].name; i++)
    {
        if (*classtable[i].name && !strcmp(args[1], classtable[i].name))
        {
            learn(i);
        }
    }
    free(call);
}

int cmd_helpmenu(int n, char **a)
{

    printf("\n");
    printf("~~Eon Pillars help menu~~\n\n");

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

int class_algebra(int nargs, char **args)
{
    printf("\nWelcome to Algebra\n\n");
    pick_activity(0);
}

int class_compsci(int nargs, char **args)
{
    printf("\nwelcome to computer science!\n\n");
    pick_activity(1);
}

int class_hacker(int nargs, char **args)
{
    printf("\nWelcome!\n");

    char buf[BUFSIZ];
    fgets(buf, BUFSIZ, stdin);

    printf("Got %s\n", buf);
    test(buf);
}

void remove_newline(char *buffer)
{
    int string_length = strlen(buffer);
    if (buffer[string_length - 1] == '\n')
    {
        buffer[string_length - 1] = '\0';
    }
}

int calculate_grade(int total_tests, int *tests)
{
    int total = 0;
    for (int i = 0; i < total_tests; i++)
    {
        total += tests[i];
    }
    return total / total_tests;
}

void pick_activity(int class_index)
{
    int activity = rand() % 4;
    switch (activity)
    {
    case 0: // test
        take_test(class_index);
        break;
    case 1: // learn
        learn(class_index);
        break;
    case 2: // learn
        learn(class_index);
        break;
    case 3: // fact
        printf("\tFun facts today!\n\n");
        break;
    case 4: // nothing
        printf("\tYup another day that we do nothing!\n\n");
        break;
    }
}

int cmd_stats(int nargs, char **args)
{
    printf("Here are your stats:\n");
    for (int i = 0; brain[i].class; i++)
    {
        printf("\t%s: %d\n", brain[i].class, brain[i].skill);
    }
}

int cmd_grades(int nargs, char **args)
{
    printf("Here are your grades:\n");
    for (int i = 0; brain[i].class; i++)
    {
        printf("\t%s: %d\n", brain[i].class, brain[i].grade);
    }
}

void take_test(int class_index)
{
    printf("\tToday we will be having a test!\n\n");
    int required_skill = (rand() % 30) + (rand() % 30) + (rand() % 40);
    if (required_skill > brain[class_index].skill)
    {
        printf("\tYou didn't do so hot on this test...");
    }
    else if (required_skill < brain[class_index].skill)
    {
        printf("\tYou did great!\n");
    }
    knowledge *class = &brain[class_index];

    int test = (100 - abs(class->skill - required_skill));

    class->tests[class->total_tests] = test;
    class->total_tests += 1;

    class->grade = calculate_grade(class->total_tests, class->tests);

    printf("\tYou got a %d\n\n", test);
}

void learn(int class_index)
{
    printf("\tToday we will be learning!\n\n");
    int learnd = rand() % 100;

    if (learnd <= 50)
    {
        printf("\tYou were probably better off staying at home today\n");
    }

    else if (learnd <= 70)
    {
        printf("\tYou learned pretty well today!");
    }

    else if (learnd <= 90)
    {
        printf("\tNice job paying attention!\n");
    }

    else if (learnd == 100)
    {
        printf("\tS Rank!\n");
    }

    knowledge *class = &brain[class_index];
    class->skill += learnd;
    printf("\n");
    return;
}
