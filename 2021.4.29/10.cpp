#include <iostream>
#include <string>
/*this就是指针，这个指针只可以指向这个类，不可更改。*/
//this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
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