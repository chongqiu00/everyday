//��ģ��������
#include <iostream>
template<class AgeType, class NameType>
class Person{
    public:
    Person(AgeType age, NameType name);
    void show(void);

    AgeType m_age;
    NameType m_name;
};

template<class AgeType, class NameType>
Person<AgeType, NameType>::Person(AgeType age, NameType name)
:m_age(age), m_name(name){}

template<class AgeType, class NameType>
void Person<AgeType, NameType>::show(void){
    std::cout << m_age << m_name << std::endl;
    return;
}

//ֱ��ָ����ĳ�Ա������������
void show(Person<int, std::string> p){
    std::cout << "ֱ��ָ����ĳ�Ա������������";
    std::cout << p.m_age << p.m_name << std::endl;
    return;
}
//�����ģ�黯
template<class AgeType, class NameType>
void show(Person<AgeType, NameType> p){
    std::cout << "�����ģ�黯";
    std::cout << p.m_age << p.m_name << std::endl;
    return;
}
//��ģ�黯
template<class T>
void show(T p){
    std::cout << "��ģ�黯";
    p.show();
}

int main(int argc, char* argv[]){
    Person<int, std::string> p1(12, "zww");
    show(p1);
    show<int, std::string>(p1);
    show<Person<int, std::string>>(p1);
    return 0;
}