#include <iostream>
//静态成员。
//创建一个独一无二的类。
//可以做到赋值类的功能。
class Singleton
{
    public:
    void show()
    {
        std::cout << m_name << m_age << std::endl;
    }

    static Singleton& Get()
    {
        static Singleton instance; //创建一个静态类。
        return instance;
    }

    void Hello()
    {
        std::cout << "hello" << std::endl;
    }

    static std::string m_name;
    static int m_age;
    
};

std::string Singleton::m_name = "zww";
int Singleton::m_age = 00;


int main(int argc, char*argv[])
{
    Singleton::Get().show();


    Singleton a;
    a.m_name = "mmm";
    a.m_age = 12;
    std::cout << a.m_name << a.m_age << std::endl;

    Singleton a_1 = a.Get();
    std::cout << a_1.m_name << a_1.m_age << std::endl;

    return 0;
}

/*
运行结果：
zww0
mmm12
mmm12
*/