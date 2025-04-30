#include "help.h"
#include <stdio.h>

int main()
{
    int x = 7, y = 6;
    //int unused_variable; // test -Wall flag
    printf("sum %d\n", add(x, y));
    return 0;
}