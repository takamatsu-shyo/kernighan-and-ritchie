#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

int main()
{
    char paindrome[strlen("paindrome") + 1] = "paindrome";
    char semordnilap[strlen("semordnilap") + 1] = "semordnilap";
    char gateman[strlen("gateman") + 1] = "gateman";

    reverse(paindrome);
    reverse(semordnilap);
    reverse(gateman);

    printf("%s\n", paindrome);
    printf("%s\n", semordnilap);
    printf("%s\n", gateman);
}
