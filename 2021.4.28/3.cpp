#include <iostream>
//引用混淆点

int main()
{
    int a = 3;
    int b = 5;

    int& p = a;
    

    std::cout << "p=" << p << std::endl;/*5*/
    std::cout << "a=" << a << std::endl;/*5*/

    p = b;//p作为a改变了a的值。

    std::cout << "p=" << p << std::endl;/*5*/
    std::cout << "a=" << a << std::endl;/*5*/
    std::cout << "b=" << b << std::endl;/*5*/

    return 0;
}

/*
引用就是给一个变量起了一个别名。不会给引用申请一个内存空间的。
*/