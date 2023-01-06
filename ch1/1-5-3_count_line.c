#include <stdio.h>

main()
{
    int c, nl, nb, nt, nn;

    nl = nb = nt = nn  = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            nl++;
        else if (c == ' ')
            nb++;
        else if (c == '\t')
            nt++;
        else if (c == '\n')
            nn++;


    printf("nl,  nb,  nt,  nn\n");
    printf("%4d %4d %4d %4d\n", nl, nb, nt, nn);
}
