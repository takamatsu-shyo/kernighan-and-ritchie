#include <stdio.h>

int main() /* count digits, white space, others */
{
    int c, i, nwhite, nothers, ndigit[10];
    
    nwhite = nothers = 0;
    for (int i = 0; i < 10; i++)
        ndigit[i] = 0;

    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case '0':  case '1': case '2': case '3': case '4':
            case '5':  case '6': case '7': case '8': case '9':
                ndigit[c - '0']++;
//                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            //case ' ':
            //    printf("illegal case?");
            default:
                nothers++;
        }
    }

    printf("digits =");
    for(int i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", wspace = %d, other = %d\n", nwhite, nothers);

    return 0;
}
