#include "all_print.h"
#include "bogosort.h"


int is_sorted(int v[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (v[i] > v[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void durstenfeld_shuffle(int v[], int length)
{
    srand(time(NULL));
    int r, tmp;

    for (int i = 0; i < length; i++)
    {
        r = rand() % length;
        tmp = v[i];
        v[i] = v[r];
        v[r] = tmp;
    }
}

void bogosort(int v[], int length)
{
    while (is_sorted(v, length) == 0)
    {
        durstenfeld_shuffle(v, length);
    }
}
