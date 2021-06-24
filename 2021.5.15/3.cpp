#include <iostream>

int main(void)
{
    uint32_t arr[5] = {1, 2, 3, 4, 5};

    uint32_t* p = arr;
    
    printf("%X\n", p);
    p++;
    printf("%X\n", p);
}