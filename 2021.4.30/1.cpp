/*��43����Cherno C++�������֡�C++�Ķ��������ڣ�ջ�����������ڣ�*/
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
    Entity entity_1;//���������������ͷš�

    Entity* entity_2 = new Entity(); //���������������ͷš�
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
    ScopedPtr e = new Entity(); //���Զ����ٶ������ڴ���䡣
    /*���н����
    Create Entity!
    Delete Entity!
    */
}

// int* CreateArray()
// {
//     int array[50]; //��ջ�ϴ�����һ�����飬һ���뿪����������ڴ�ͻᱻ��������޷�����������ٵ��ڴ�ռ䡣
//     return array;
// }
int main(int argc, char* argv[])
{
    //text01();
    text02();

    return 0;
}