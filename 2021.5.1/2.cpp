//��46����Cherno C++�������֡�C++�ļ�ͷ������
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
     // ������������ �����˵��entity��const�ģ�Ҳ����˵���޷��ı�entity�еı�����
      // ������ȴ������һ�����Ըı������print����ʹ���ڴ�����printû�иı��κα�����
     // ����ʵprint�Ǳ�����ı�ģ�������print����֮ǰ��const��ͻ�ˣ�
     // ��˱����print����Ϊ���ܸı�����ĺ������ſ��Ա����ܸı������const entity����
    const Entity* operator-> () const //ע�⣬��������ǳ�������
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