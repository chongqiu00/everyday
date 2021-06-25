#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Person{
public:
    Person(int age, std::string m_name);
public:
    int m_age;
    std::string m_name;
};
Person::Person(int age, std::string name)
:m_age(age), m_name(name){}

int main(int argc, char* argv[])
{
    std::vector<Person> vp;
    Person p1(1, "z");
    Person p2(2, "w");
    Person p3(3, "w");

    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    for ( std::vector<Person>::iterator it=vp.begin(); it != vp.end(); it++){
        std::cout << it->m_age << " " << it->m_name << std::endl;
    }

    return 0;
}