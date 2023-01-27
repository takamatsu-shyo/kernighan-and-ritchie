#include <cstdio>

/*binarysearch: find x in v[0] <= v[1] .... <= v[n-1] */
int binarysearch(int x, int v[], int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2; // .5?
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; // found match
    }
    return -1; // no match
}

main()
{
    int num = 512;
    int list[num];

    for (int i = 0; i < num; i++)
    {
        list[i] = i * 2;
    }

    printf("%d\n", binarysearch(14, list, num));
    printf("%d\n", binarysearch(3, list, num));

    /* test division */
    printf("5/2=%d\n", 5/2);

    /* test length of int */
    int increment = 0;
    int max_int = 0;
    for (double i = 0; increment == i ;i++, increment++)
    {
        max_int = i;
    }

    int bit = 0;
    int print_max_int = max_int;
    int print_min_int = max_int + 1; // Intentional overflow
    while(max_int > 0)
    {
        max_int /= 2;
        bit++;
    }
    printf ("MAX int %d, MIN int %d, %dbit\n", print_max_int, print_min_int, (bit + 1) * 2);
}
