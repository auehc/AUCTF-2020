#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    seteuid( 1002 );   // you can set it at run time also
    system( "/home/level2/random_dirs.sh" );
    return 0;
 }
