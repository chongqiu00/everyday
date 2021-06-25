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
    std::vector<std::vector<Person>> vvp;
    std::vector<Person> vp1;
    std::vector<Person> vp2;
    Person p1(1, "z");
    Person p2(2, "w");
    Person p3(3, "w");

    vp1.push_back(p1);
    vp1.push_back(p2);
    vp1.push_back(p3);

    vp2.push_back(p3);
    vp2.push_back(p2);
    vp2.push_back(p1);

    vvp.push_back(vp1);
    vvp.push_back(vp2);

    for ( std::vector<std::vector<Person>>::iterator it=vvp.begin(); it != vvp.end(); it++){
        for ( std::vector<Person>::iterator itt=(*it).begin(); itt!=(*it).end(); itt++){
            std::cout << itt->m_age << " " << itt->m_name << "==";
        }
        std::cout << std::endl;
    }
    return 0;
}