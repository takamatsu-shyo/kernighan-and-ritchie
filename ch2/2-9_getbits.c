#include <cstdio>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

main(void)
{
    // and
    int four = 017;
    int eight = 0177;

    printf("%d\n", four); 

    printf("%d\n", eight); 
    eight = eight & 017;
    printf("%d\n\n", eight); 

    // unary
    int x = 017;
    x = x & ~07;
    printf("%d\n\n", x);

    int y = 017777;
    printf("%d\n", y);
    printf("%d\n", y >> 2);
    printf("%d\n", (y >> 2 & ~(~0 << 4)));
}
