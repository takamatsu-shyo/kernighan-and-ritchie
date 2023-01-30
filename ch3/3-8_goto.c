#include <cstdio>

int main()
{
    int ilist[5];
    int jlist[5];
    int found_int;

    for (int k = 0; k < 5; k++)
    {
        ilist[k] = (k + 1) * 3;
        jlist[k] = (k + 1) * 5;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (ilist[i] == jlist[j])
            {
                found_int = ilist[i];
                goto found;
           } 
        }
    }

    printf("No common element\n");
    return 0;

found:
    printf("Found common element: %d\n", found_int);
    return 1;
}
