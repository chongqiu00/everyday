#include <iostream>

#define hehe(x, y) x##y

int main(void)
{
    char string[] = "hello world!";
    printf("%s\n", hehe(str, ing));
    /*运行结果：
    hello world!*/
    return 0;
}