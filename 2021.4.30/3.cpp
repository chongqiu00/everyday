/*显示调用和隐式调用*/

#include <iostream>

class Text_1
{
    public:
    Text_1(int number)
    {
        std::cout << number << std::endl;
    }

};

class Text_2
{
    public:
    explicit Text_2(int number) //不可隐式调用。
    {
        std::cout << number << std::endl;
    }
};
int main()
{
    Text_1 t_1 = 10; //支持显示隐式调用
    Text_1 t_2(10);

    //Text_2 t_3 = 10; //不支持隐式调用
    Text_2 t_4(10); //支持显示调用。
    return 0;
}