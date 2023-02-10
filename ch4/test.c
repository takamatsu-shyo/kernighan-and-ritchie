#include <stdio.h>

int no_answer()
{
    return 1;
    printf("no return?\n");
}

main()
{
    if(no_answer())
        printf("return 1\n");
    else
        printf("return 0?\n");
}
