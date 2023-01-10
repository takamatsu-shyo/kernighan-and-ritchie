#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char *line, int max);

int main(int argc, char *argv[])
{
    int found = 0;
    char line[MAXLINE];

    if (argc != 2)
        printf("Usage: find foobar\n");
    else
        while (_getline(line, MAXLINE) > 0)
            if(strstr(line, argv[1]) != NULL)
            {
                printf("%s", line);
                found++;
            }

    return found;
}

/* getline: get line into s, return length */
int _getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

