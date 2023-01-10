#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
    int found = 0;
    char line[MAXLINE];

    if (argc != 2)
        printf("Usage: find foobar\n");
    else
    {
        while (getline(line, MAXLINE) :wq)
            if(strstr(line, argv[1]) != NULL)
            {
                found++;
                printf("%s", line)
            }
    }

    return found;
}
