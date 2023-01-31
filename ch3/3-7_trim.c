#include <string.h>
#include <stdio.h>

/* trom: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;
    for (n = strlen(s) -1; n >=0; n--)
    {
        if (s[n] != ' ' && s[n] != '\n' && s[n] != '\t')
            break;
        s[n+1] = '\0'; 
    }

    return n;
}

int main()
{
    char s[6] = "tl\t\n ";
    printf("%s %d\n", s, strlen(s));

    int n = trim(s);
    printf("%s len: %d %d\n", s, n, strlen(s));

    return 0;
}
