/*
剑指Offer:
思考运行的情况。
*/

#include <iostream>

class A
{
    private:
    int value;

    public:
    A(int n)
    : value(n){}
    A( A& other )
    //A( A other) //形参传值，会拷贝赋值
    {
        value = other.value;
    }

    void Printf()
    {
        std::cout << this->value << std::endl;
    }

};
int main(int arggc, char* argv[])
{
    A a = 10;
    A b = a;
    b.Printf();

}

/*
拷贝构造函数不允许赋值其构造函数。
*/