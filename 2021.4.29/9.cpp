#include <iostream>
//所以尽可能的使用：初始化类成员。
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
    Entity m_entity; //此处创建了一个类，成员也是一个个体啊，这样就是调用了无参构造函数。
    public:
    Player()
    :m_entity(Entity(8)) //在此处初始化上面创建的类。
    {
       // m_entity = Entity(8); //此处就是新创建了一个Entity有参对象。
    }
};
//所以尽可能的使用：初始化类成员。
/*
使用：初始化：
Create Entity
Cretr Entity 8
不使用：初始化运行结果：
Cretr Entity 8
*/
int main()
{
    Player player = Player();
    return 0;
}