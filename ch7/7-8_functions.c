#include <stdio.h>
#include <stdlib.h>

main()
{
    printf("%d\n", system("date"));
    printf("%d\n", system("ls -ltrac"));
    printf("%i\n", system("exa -l"));
}
