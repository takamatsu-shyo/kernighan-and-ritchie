#include <cstdio>

/* bitcount: count 1 bits in x */
int bitcount(unsigned int x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    return b;
}

main(void)
{
    int my_x = 016;
    printf("%d\n", bitcount(my_x));
}
