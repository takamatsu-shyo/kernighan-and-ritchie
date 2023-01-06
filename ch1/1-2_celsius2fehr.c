#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -100;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper)
    {
        //celsius = (5.0/9.0) * (fahr-32.0);
        fahr = (9.0/5.0) * celsius + 32;
        printf("%4.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
