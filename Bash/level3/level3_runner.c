#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    setuid( 1003 );   // you can set it at run time also
    system( "/home/level3/passcodes.sh" );
    return 0;
 }
