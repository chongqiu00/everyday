/*
���ڣ�2021��4��28
�༭�ˣ�chongqiu00
˵����
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <ctime>
/*
��������Person�Զ����������ͽ�������Person�����������������䡢��ߡ�
���򣺰�����������������������ͬ������߽��н���
*/

class Person
{
    public:
    Person(std::string name, int age, int height)
    :m_Name(name), m_Age(age), m_Height(height){}

    std::string m_Name;
    int m_Age;
    int m_Height;
};

class Compare
{
    public:
    bool operator() (Person &p1, Person &p2)
    {
        if ( p1.m_Age == p2.m_Age)
        {
            return (p1.m_Height < p2.m_Height);
        }
        else
        {
            return (p1.m_Age < p2.m_Age);
        }
    }
};

class Print
{
    public:
    void operator() (Person &p)
    {
        std::cout << "������" << p.m_Name << "���䣺" << p.m_Age << "��ߣ�" << p.m_Height << std::endl;
    }
};

int main(int argc, char* argv[])
{
    //����
    Person p1("����", 35 , 175);
	Person p2("�ܲ�", 45 , 180);
	Person p3("��Ȩ", 40 , 170);
	Person p4("����", 25 , 190);
	Person p5("�ŷ�", 35 , 160);
	Person p6("����", 35 , 200);

    //���
    std::vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);

    std::sort(v.begin(), v.end(), Compare());

    //������ʾ
    for_each(v.begin(), v.end(), Print());

    return 0;
}