#include <iostream>
//���Ծ����ܵ�ʹ�ã���ʼ�����Ա��
#include <string>
class Entity
{
    public:
    Entity()
    {
        std::cout << "Create Entity" << std::endl;
    }
    Entity(int number)
    {
        std::cout << "Cretr Entity " << number << std::endl;
    }
};

class Player
{
    private:
    Entity m_entity; //�˴�������һ���࣬��ԱҲ��һ�����尡���������ǵ������޲ι��캯����
    public:
    Player()
    :m_entity(Entity(8)) //�ڴ˴���ʼ�����洴�����ࡣ
    {
       // m_entity = Entity(8); //�˴������´�����һ��Entity�вζ���
    }
};
//���Ծ����ܵ�ʹ�ã���ʼ�����Ա��
/*
ʹ�ã���ʼ����
Create Entity
Cretr Entity 8
��ʹ�ã���ʼ�����н����
Cretr Entity 8
*/
int main()
{
    Player player = Player();
    return 0;
}