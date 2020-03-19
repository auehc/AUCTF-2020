#include "commandline.h"




/*
 * Command line main loop.
 */
void* commandline()
{

     char* buffer;

     buffer = (char*)malloc(BUFSIZ * sizeof(char));
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
     return (void*)NULL;
}
/*
 * Process a single command.
 */
int cmd_dispatch(char* cmd)
{
     char* args[MAXMENUARGS];
     int nargs = 0;
     char* word;

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
               if (cmdtable[i].func != NULL) {

                    result = cmdtable[i].func(nargs, args);
                    return result;
               }
          }
     }

     printf("%s: Command not found\n", args[0]);
     return EINVAL;
}

/*
 * The quit command.
 */
int cmd_quit(int nargs, char** args)
{
     printf("Quiting AUCalc... \n");

     exit(0);
}

/*
 * Display menu information
 */
int cmd_helpmenu(int n, char** a)
{

     printf("\n");
     printf("AUCalc help menu\n");

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

int cmd_subtract(int n, char** a) {
     if (n < 3) {
          return 1;
     }
     int out = atoi(a[1]);
     for (int i = 2; i < n; i++) {
          out -= atoi(a[i]);
     }

     printf("%d\n", out);
     return 0;
}
int cmd_add(int n, char** a) {
     if (n < 3) {
          return 1;
     }
     int out = atoi(a[1]);
     for (int i = 2; i < n; i++) {
          out += atoi(a[i]);
     }

     printf("%d\n", out);
     return 0;
}

int cmd_multiply(int n, char** a) {
     if (n < 3) {
          return 1;
     }
     float out = atof(a[1]);
     for (int i = 2; i < n; i++) {
          out *= atof(a[i]);
     }

     printf("%f\n", out);
     return 0;
}

int cmd_div_secret(int n, char** a) {
     printf(TODO);
     if (n < 3) {
          return 1;
     }
     int out = atoi(a[1]);

     for (int i = 2; i < n; i++) {
          out /= atoi(a[i]);
     }

     printf("%d\n", out);
     return 0;
}

int cmd_mul_secret(int n, char** a) {
     printf(TODO);
     if (n < 3) {
          return 1;
     }
     int out = atoi(a[1]);

     for (int i = 2; i < n; i++) {
          out *= atoi(a[i]);
     }

     printf("%d\n", out);
     return 0;
}

int cmd_divide(int n, char** a) {
     ;
     if (n < 3) {
          return 1;
     }
     float out = atof(a[1]);

     for (int i = 2; i < n; i++) {

          out /= atof(a[i]);
     }

     printf("%f\n", out);
     return 0;
}

void remove_newline(char* buffer)
{
     int string_length = strlen(buffer);
     if (buffer[string_length - 1] == '\n')
     {
          buffer[string_length - 1] = '\0';
     }
}