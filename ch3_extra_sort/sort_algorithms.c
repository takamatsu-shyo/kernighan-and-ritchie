#include "sort_algorithms.h"

void bubblesort(int v[], int length)
{
    int tmp;
    int swap = 1;
    while (swap == 1)
    {
        swap = 0;
        for (int i = 0; i < length - 1 ; i++) 
        {
           if (v[i] > v[i + 1])
            {
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                swap = 1;
            }
        }
    }
}

void k_sort(int v[], int vr[], int length)
{
    int k = 0;
    //for (int i = INT_MIN; i < INT_MAX; i++)
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == v[j])
            {
                vr[k] = i;
                k++;
            }
        }
    }
}

void ky_sort(int v[], int vr[], int length)
{
    int max, min;
    max = min = v[0];
 
    for (int i = 0; i < length; i++)
    {
        if (v[i] < min)
            min = v[i];
        else if (v[i] > max)
            max = v[i];
   }

    int k = 0;
    for (int i = min; i <= max; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == v[j])
            {
                vr[k] = i;
                k++;
            }
        }
    }
}

