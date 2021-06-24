#include <iostream>

class Make{
    public:
    virtual void shui(void) = 0;
    virtual void liao(void) = 0;
    void make()
    {
        shui();
        liao();
    }

};

class Coffer:public Make
{
    public:
    virtual void shui(void) override
    {
        std::cout << "����ˮ" << std::endl;
        return;
    }
    virtual void liao(void) override
    {
        std::cout << "�����ȷ�" << std::endl;
        return;
    }
};

int main()
{
    Coffer* coffer = new Coffer();
    coffer->make();
    return 0;
}