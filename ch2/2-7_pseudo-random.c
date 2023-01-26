#include <cstdio>

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0...32767 */
int rand(void)
{
    next = next * 1234567890 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand */
void srand(unsigned int seed)
{
    next = seed;
}

main(void)
{
    printf("%d\n", rand());
    srand(63);
    printf("%d\n", rand());
}
