#include <cstdio>

/* strlen: return length of s */
int strlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

main()
{
    char foobar[7] = "foobar";
    printf("%d %s",strlen(foobar), foobar);
}
