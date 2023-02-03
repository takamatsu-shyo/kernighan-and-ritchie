#include "3-x_sort-algorithms.h"
#include "all_print.h"
#include "bogosort.h"
#include <stdio.h>
#include <time.h>

void copy_array(int v[], int w[], int length)
{
    for (int i = 0; i < length; i++)
        w[i] = v[i];
}


int main()
{
    //int length = INT_MAX;
    //int length = 256;
    int length = 4;
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
 
    printf("Bogo sort\n");
    all_print(array, length);
    int bogo_array[length];
    copy_array(array, bogo_array, length);
    bogosort(bogo_array, length);
    all_print(bogo_array, length);
 
   return 0;
}
