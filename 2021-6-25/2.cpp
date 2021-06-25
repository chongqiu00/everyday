//模块具体化
#include <iostream>

class Person{
    public:
    Person(int age, std::string name);

    int m_age;
    std::string m_name;
};
Person::Person(int age, std::string name)
    : m_age(age), m_name(name){}

template<typename T>
bool Compare(T p1, T p2)
{
    if (p1==p2)
        return true;
    else
        return false;
}
//模块具体化
template<>
bool Compare(Person p_1, Person p_2){
    if ( (p_1.m_age == p_2.m_age) && (p_1.m_name == p_2.m_name) ) 
        return true;
    else 
        return false;
}

int main(int argc, char* argv[])
{
    Person p_1(12, "zww");
    Person p_2(12, "zww");
    Person p_3(23, "zww");

    if (Compare(p_1, p_3)){
        printf("==\n");
    }
    else{
        printf("!=\n");
    }

    return 0;
}