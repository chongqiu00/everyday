#include <iostream>
#include <string>
/*this����ָ�룬���ָ��ֻ����ָ������࣬���ɸ��ġ�*/
//this �� const ָ�룬����ֵ�ǲ��ܱ��޸ĵģ�һ����ͼ�޸ĸ�ָ��Ĳ������縳ֵ���������ݼ��ȶ��ǲ�����ġ�
class Entity
{
    public:
    int x,y;
    public:
    Entity(int x, int y)
    {
        Entity* e = this;
        e->x = x;
        e->y = y;
    }
};
int main()
{
    Entity e = Entity(1, 2);
    std::cout << e.x << " " << e.y << std::endl;

    return 0;
}