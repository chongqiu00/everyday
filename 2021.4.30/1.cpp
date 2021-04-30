/*【43】【Cherno C++】【中字】C++的对象生存期（栈作用域生存期）*/
#include <iostream>

class Entity
{
    public:
    Entity()
    {
        std::cout << "Create Entity!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Delete Entity!" << std::endl;
    }
};
void text01()
{
    Entity entity_1;//创建运行完程序后释放。

    Entity* entity_2 = new Entity(); //创建运行完程序后不释放。
}

class ScopedPtr
{
    private:
    Entity* m_Ptr;
    public:
    ScopedPtr(Entity* ptr)
    :m_Ptr(ptr){}
    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

void text02()
{
    ScopedPtr e = new Entity(); //可自动销毁堆区的内存分配。
    /*运行结果：
    Create Entity!
    Delete Entity!
    */
}

// int* CreateArray()
// {
//     int array[50]; //在栈上创建的一个数组，一旦离开这个作用域，内存就会被清楚，而无法控制这个开辟的内存空间。
//     return array;
// }
int main(int argc, char* argv[])
{
    //text01();
    text02();

    return 0;
}