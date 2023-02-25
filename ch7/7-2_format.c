#include <stdio.h>

main()
{
    char hw[12] = "Hello, World";
    printf("%s\n", hw);
    printf("%10s\n", hw);
    printf("%.10s\n", hw);
    printf("%-10s\n", hw);

    printf("%15s\n", hw);
    printf("%.15s\n", hw);
    printf("%-15s\n", hw);

    printf("%15.10s\n", hw);
    printf("%-15.10s\n", hw);

    printf("%f\n", 29.01);
    printf("%f\n", 129.02);

    printf("%3f\n", 29.01);
    printf("%3f\n", 129.02);

    printf("%.3f\n", 29.01);
    printf("%.3f\n", 129.02);

    printf("%-3f\n", 29.01);
    printf("%-3f\n", 129.02);

    printf("%10.3f\n", 29.01);
    printf("%10.3f\n", 129.02);

    printf("0%o\n", 29);
    printf("0x%x\n", 124);



}
