//��̬
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
        std::cout << "è��˵��" << std::endl;
    }
};

class Dog:public Speak
{
    public:
    virtual void who() override
    {
        std::cout << "����˵��" << std::endl;
    }
};

//�ӿ�
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