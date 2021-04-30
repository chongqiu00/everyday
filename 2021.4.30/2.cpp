/*
【44】【Cherno C++】【中字】C++的智能指针
1. 当你调用new时，你无需调用delete, 甚至我们也可以无需调用new。
2. 智能指针不可以拷贝赋值。（当两个智能指针同时指向一个内存空间时，其中一个智能指针将其销毁，就意味着指向的那块内存空间被释放了，这样另一个智能指针就会产生歧义。）
3. 
当我们不想分配在堆上面的内存手工删除，使用智能指针；
当需要对象共享内存时，使用共享指针；
当我们需要拷贝共享指针而不产生计数时，使用弱指针。
*/

#include <iostream>
#include <memory> //使用智能指针的头文件。

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

void text01() //智能指针
{
    std::unique_ptr<Entity> entity_1(new Entity()); //必须显示调用。不允许隐式转化
    //std::unique_ptr<Entity> entity = new Entity(); // 错误。
    std::unique_ptr<Entity> entity_2 = std::make_unique<Entity>(); //如果构造函数抛出异常，它会稍微安全一些。
    //std::unique_ptr<Entity> entity_0 = entity; //不可赋值。
    /*运行结果：
    Create Entity!
    Create Entity!
    Delete Entity!
    Delete Entity!*/
}

void text02() //共享指针
{
    std::shared_ptr<Entity> entity_1;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); //产生计数值，当计数值为0时销毁，即共享内存的指针全部销毁共享内存才会被销毁。
         std::cout << "zww" << std::endl;
        entity_1 = sharedEntity;
         std::cout << "zww" << std::endl;
    }
     std::cout << "zww" << std::endl;
    /*运行结果：
    Create Entity!
    zww
    zww
    zww
    Delete Entity!*/
}

void text03() //弱指针
{
    std::weak_ptr<Entity> entity_1;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); 
        std::cout << "zww" << std::endl;
        entity_1 = sharedEntity;    //不产生计数值，只作为引用，不确定对象是否还存在。
        std::cout << "zww" << std::endl;
    }
    std::cout << "zww" << std::endl;
    /*运行结果：
    Create Entity!
    zww
    zww
    Delete Entity!
    zww*/    
}


int main(int argc, char* argv[])
{

    //text01();
    //text02();
    text03();
    
    return 0;
}