#include <cstdio>

int main()
{
    int i_array[5];
    int j_array[5];
    int found_int;

    for (int k = 0; k < 5; k++)
    {
        i_array[k] = (k + 1) * 3;
        j_array[k] = (k + 1) * 5;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i_array[i] == j_array[j])
            {
                found_int = i_array[i];
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
