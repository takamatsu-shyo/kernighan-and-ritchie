#include <stdio.h>

main()
{
    printf("%i \n", EOF);
    //printf(EOF);

    int c;

    while ((c = getchar()) != EOF)
        while (c != ' ')
            ;
        printf("%c", c);
        //putchar(c);
}
