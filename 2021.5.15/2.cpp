#include <iostream>

int atoi(const char* p)
{
    char* s = (char*) p;
    
    int sum = 0;
    if ( s == nullptr )
    {
        return -1;
    }
    else
    {
        
        while ( *s != '\0')
        {
            sum += *(s++) * 10;
        }
    }
    return sum;
}
int main(void)
{
    printf("sum = %d\n", atoi("333"));
    return 0;
}