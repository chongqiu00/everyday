/*
��44����Cherno C++�������֡�C++������ָ��
1. �������newʱ�����������delete, ��������Ҳ�����������new��
2. ����ָ�벻���Կ�����ֵ��������������ָ��ͬʱָ��һ���ڴ�ռ�ʱ������һ������ָ�뽫�����٣�����ζ��ָ����ǿ��ڴ�ռ䱻�ͷ��ˣ�������һ������ָ��ͻ�������塣��
3. 
�����ǲ�������ڶ�������ڴ��ֹ�ɾ����ʹ������ָ�룻
����Ҫ�������ڴ�ʱ��ʹ�ù���ָ�룻
��������Ҫ��������ָ�������������ʱ��ʹ����ָ�롣
*/

#include <iostream>
#include <memory> //ʹ������ָ���ͷ�ļ���

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

void text01() //����ָ��
{
    std::unique_ptr<Entity> entity_1(new Entity()); //������ʾ���á���������ʽת��
    //std::unique_ptr<Entity> entity = new Entity(); // ����
    std::unique_ptr<Entity> entity_2 = std::make_unique<Entity>(); //������캯���׳��쳣��������΢��ȫһЩ��
    //std::unique_ptr<Entity> entity_0 = entity; //���ɸ�ֵ��
    /*���н����
    Create Entity!
    Create Entity!
    Delete Entity!
    Delete Entity!*/
}

void text02() //����ָ��
{
    std::shared_ptr<Entity> entity_1;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); //��������ֵ��������ֵΪ0ʱ���٣��������ڴ��ָ��ȫ�����ٹ����ڴ�Żᱻ���١�
         std::cout << "zww" << std::endl;
        entity_1 = sharedEntity;
         std::cout << "zww" << std::endl;
    }
     std::cout << "zww" << std::endl;
    /*���н����
    Create Entity!
    zww
    zww
    zww
    Delete Entity!*/
}

void text03() //��ָ��
{
    std::weak_ptr<Entity> entity_1;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); 
        std::cout << "zww" << std::endl;
        entity_1 = sharedEntity;    //����������ֵ��ֻ��Ϊ���ã���ȷ�������Ƿ񻹴��ڡ�
        std::cout << "zww" << std::endl;
    }
    std::cout << "zww" << std::endl;
    /*���н����
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