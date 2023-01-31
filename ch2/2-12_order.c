#include <cstdio>
#include <math.h>

void my_print(int *a, int size)
{
    for (int j = 0; j < size; j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n");
}

void my_init(int *a, int size)
{
    for (int j = 0; j < size; j++)
    {
        a[j] = 0;
    }
}


main(void)
{
    int size = 4;
    int a[size];

    my_init(a, size);
    my_print(a, size);

    int i = 0;
    a[i] = i++;
    my_print(a, size);

    my_init(a, size);
    i = 1;
    a[i] = i++;
    my_print(a, size);

    my_init(a, size);
    i = 2;
    a[i] = i++;
    my_print(a, size);

    float n = 2;
    printf("%f %f\n", ++n, pow(2, n));
}
