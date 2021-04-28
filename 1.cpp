/*
日期：2021、4、28
编辑人：chongqiu00
说明：
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <ctime>
/*
描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高。
规则：按照年龄进行升序，如果年龄相同按照身高进行降序。
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
        std::cout << "姓名：" << p.m_Name << "年龄：" << p.m_Age << "身高：" << p.m_Height << std::endl;
    }
};

int main(int argc, char* argv[])
{
    //创建
    Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

    //入库
    std::vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);

    std::sort(v.begin(), v.end(), Compare());

    //排序显示
    for_each(v.begin(), v.end(), Print());

    return 0;
}