#include "sort_lib.h"

void all_print(int v[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", v[i]);
    }
    printf("\n");
}

void copy_array(int v[], int w[], int length)
{
    for (int i = 0; i < length; i++)
        w[i] = v[i];
}

