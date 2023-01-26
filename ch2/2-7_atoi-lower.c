#include <cstdio>

/* atoi: convert s to integer */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = n * 10 + (s[i] - '0');
        
    return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

main()
{
    char foobar[4] = "987";
    printf("%d %s\n",atoi(foobar), foobar);

    char foo[4] = "XYZ";
    printf("%d", lower(foobar[0]));
}
