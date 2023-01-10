#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "Jan", "Feb", "Mar",
        "Apr", "May", "Jun",
        "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

/* day_of_year: set day of year from month&day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;

}

void main()
{
    printf("%i\n", day_of_year(2023,12,5));

    int passed_month, passed_day;
    month_day(2023, 165, &passed_month, &passed_day);
    printf("%d %d\n", passed_month, passed_day);

    month_day(2023, 166, &passed_month, &passed_day);
    printf("%s %d\n", month_name(passed_month), passed_day);
}
