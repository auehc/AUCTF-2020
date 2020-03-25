#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    setgid( 1004 );   // you can set it at run time also
    system( "/home/level4/print_file.sh" );
    return 0;
 }