#include <ctype.h>
#include <stdio.h>

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        printf("%c %f/",s[i], val);
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
        printf("%c %f/",s[i], val);
    }
    return sign * val / power;;
}

main()
{
    printf("%f\n\n", atof("10"));
    printf("%f\n\n", atof("10.0"));
    printf("%f\n\n", atof("10.0"));
    printf("%f\n\n", atof("+10.0"));
    printf("%f\n\n", atof("-10.0"));
    printf("%f\n\n", atof("10.1"));
    printf("%f\n\n", atof("99.99"));
    printf("%f\n\n", atof("-99.99"));
    printf("%f\n\n", atof("+99.9999"));
}
