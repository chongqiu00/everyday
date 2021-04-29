#include <stdio.h>

float fun(double x)
{
    float a;
    if ( x <=10 )
    a = x*2.5;
    else
    a = 10*2.5 + (x-10)*1.5;
    return a;
}

int main()
{
    float a, x;
    //scanf("%lf", &x);
    //printf("%lf");
    a = fun(10);
    printf("%2lf\n", a);
}