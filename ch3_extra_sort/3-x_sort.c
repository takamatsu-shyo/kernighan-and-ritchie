#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void all_print(int v[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", v[i]);
    }
    printf("\n");
}

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
void copy_array(int v[], int w[], int length)
{
    for (int i = 0; i < length; i++)
        w[i] = v[i];
}


int main()
{
    //int length = INT_MAX;
    //int length = 256;
    int length = 10;
    printf("Length %u\n", length);

    srand(time(NULL));
    int array[length], sort_array[length];
    for (int i = 0; i < length; i++)
    {
        //array[i] = rand(); 
        array[i] = length - i; 
    }
    all_print(array, length);


    printf("Bubble sort\n");
    copy_array(array, sort_array, length);
    all_print(sort_array, length);
    bubblesort(sort_array, length);
    all_print(sort_array, length);
 
    printf("k-sort\n");
    all_print(array, length);
    int k_array[length];
    k_sort(array, k_array, length);
    all_print(k_array, length);

    printf("ky-sort\n");
    all_print(array, length);
    int ky_array[length];
    ky_sort(array, ky_array, length);
    all_print(ky_array, length);
 
   return 0;
}
