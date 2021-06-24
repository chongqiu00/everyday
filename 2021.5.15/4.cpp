#include <iostream>

int main(void)
{
    int x1 = 0;
    int x2 = 0;
    int x3 = 1;

    if ( x1 && (x2 | x3) )
    printf("*************\n");
    else
    printf("++++++++");
    return 0;
}