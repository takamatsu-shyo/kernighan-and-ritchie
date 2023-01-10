#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char *line, int max);

int main(int argc, char *argv[])
{
    int found = 0, inverse = 0, show_line_num = 0;
    int c;
    long line_number = 0;
    char line[MAXLINE];

    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch (c) 
            {
                case 'x':
                    inverse = 1;
                    break;
                case 'l':
                    show_line_num = 1;
                    break;
                default:
                    argc = 0;
                    found = -1;
                    printf("Invalid option %c\n", c);
                    break;
            }

    if (argc != 1)
        printf("Usage: find -x -l pattern\n");
    else
        while (_getline(line, MAXLINE) > 0)
        {
            line_number++;
            if ((strstr(line, *argv) != NULL) != inverse)
            {
                if (show_line_num)
                    printf("%ld: ", line_number);
                printf("%s", line);
                found++;
            }
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

