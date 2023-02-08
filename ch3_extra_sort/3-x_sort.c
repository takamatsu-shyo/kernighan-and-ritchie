#include "sort_algorithms.h"
#include "sort_lib.h"
#include "bogosort.h"
#include <stdio.h>
#include <time.h>

int main()
{
    int length = 4;
    printf("Length %u\n", length);

    int array[length];
    get_array(array, length);
    print_array(array, length);


    printf("Bubble sort\n");
    int bubble_array[length];
    copy_array(array, bubble_array, length);
    print_array(bubble_array, length);
    bubblesort(bubble_array, length);
    print_array(bubble_array, length);
 
    printf("k-sort\n");
    print_array(array, length);
    int k_array[length];
    k_sort(array, k_array, length);
    print_array(k_array, length);

    printf("ky-sort\n");
    print_array(array, length);
    int ky_array[length];
    ky_sort(array, ky_array, length);
    print_array(ky_array, length);
 
    printf("Bogo sort\n");
    print_array(array, length);
    int bogo_array[length];
    copy_array(array, bogo_array, length);
    bogosort(bogo_array, length);
    print_array(bogo_array, length);
 
   return 0;
}
