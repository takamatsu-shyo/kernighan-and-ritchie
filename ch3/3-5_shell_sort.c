#include <stdio.h>
#include <string.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

int main()
{
    int array[5];
    array[0] = 10;
    array[1] = 1;
    array[2] = 21;
    array[3] = 55;
    array[4] = 45;

    shellsort(array, 5);

    for (int i = 0; i < 5; i++)
        printf("%d ", array[i]);

    return 0;
}
