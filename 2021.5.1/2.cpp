//【46】【Cherno C++】【中字】C++的箭头操作符
#include <iostream>

class Entity
{
    public:
    int x;

    public:
    void Print() const{
        std::cout << "hello" << std::endl;
    };
};

class ScopedPtr
{
    private:
    Entity* m_Obj;

    public:
    ScopedPtr(Entity* entity)
    : m_Obj(entity)
    {}
    ~ScopedPtr()
    {
        delete m_Obj;
    }
     // 我是这样理解的 如果你说明entity是const的，也就是说你无法改变entity中的变量，
      // 但是你却调用了一个可以改变变量的print，即使你在代码中print没有改变任何变量，
     // 但其实print是被允许改变的，所以这print就与之前的const冲突了，
     // 因此必须把print设置为不能改变变量的函数，才可以被不能改变变量的const entity调用
    const Entity* operator-> () const //注意，这个必须是常函数，
    { 
        return m_Obj;
    }
};

void text01()
{
    const ScopedPtr e = new Entity;
    e->Print();
}

// void text02()
// {
//     struct vector3
//     {
//         float x, y, z;
//     };
  
//     int offset = (int)&((vector3*)nullptr)->x;
//     std::cout << offset << std::endl;
// }
int main()
{
    text01();
    //text02();
    return 0;
}