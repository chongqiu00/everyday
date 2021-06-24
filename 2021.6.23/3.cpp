//多态
#include <iostream>

class Speak{
    public:
    virtual void who() = 0;
};

class Cat:public Speak
{
    public:
    virtual void who() override
    {
        std::cout << "猫在说话" << std::endl;
    }
};

class Dog:public Speak
{
    public:
    virtual void who() override
    {
        std::cout << "狗在说话" << std::endl;
    }
};

//接口
void speak(Speak& people){
    people.who();
    return;
}

int main(int argc, char* argv[])
{
    Cat cat;
    speak(cat);
    return 0;
}