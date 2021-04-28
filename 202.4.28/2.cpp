/*
日期：2021、4、28
编辑人：chongqiu00
说明：vector, multimap的灵活使用。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <ctime>

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

class Work
{
    public:
    Work(std::string name)
    : m_Name(name){}

    void show()
    {
        std::cout << m_Name << "工资：" << m_Salary << std::endl; 
    }

    std::string m_Name;
    int m_Salary;
};

class Print
{
    public:
    void operator() (Work &w)
    {
        std::cout << w.m_Name << "工资：" << w.m_Salary << "元" << std::endl; 
    }
};

class Compare
{
    public:
    bool operator() (const std::pair<int, Work>& a, const std::pair<int, Work>& b)
    {
        if (a.first==b.first)
        {
            return (a.second.m_Salary < b.second.m_Salary);
        }
        return (a.first < b.first);
    }
};



//初始化10名员工，工资随机。
void CreateWork(std::vector<Work>& v);

//将员工信息入multimap容器中，员工部门编号作为其键值。
void InputMap(std::vector<Work>& v, std::multimap<int, Work>& m);

//按部门输出显示
void show(std::multimap<int, Work>& m);

int main(int argc, char* argv[])
{
    srand((unsigned int)time(NULL));
    std::vector<Work> v;
    std::multimap<int, Work> m;

    //构造10个员工对象
    CreateWork(v);
    //for_each(v.begin(), v.end(), Print());

    //构造的员工对象入map容器
    InputMap(v, m);

    //按部门输出显示
    show(m);

    return 0;
}

//初始化10名员工，工资随机。
void CreateWork(std::vector<Work>& v)
{
    char idx[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'K'};
    for (int i=0; i<10; i++)
    {
        std::string name = "员工";
        name += idx[i];
        Work w(name);
        w.m_Salary = rand() % 100000 + 5000;
        v.push_back(w);
    }
}

//将员工信息入multimap容器中，员工部门编号作为其键值。
void InputMap(std::vector<Work>& v, std::multimap<int, Work>& m)
{
    for (std::vector<Work>::iterator it=v.begin(); it!=v.end(); it++)
    {
        int depart = rand() % 3;//产生0，1，2的随机数。
        //0：研发部 1：美术部 2：管理部
        m.insert(std::pair<int, Work>(depart, *it));
    }
}

//按部门输出显示
 void show(std::multimap<int, Work>& m)
 {
     
    std::vector<std::pair<int, Work>> v(m.begin(), m.end());//将map中的元素拷贝到vector中
	std::sort(v.begin(),v.end(),Compare());//实现value的排序

    std::cout << "-------工资排名公示-----------" << std::endl;
	for (std::vector<std::pair<int, Work>>::iterator it=v.begin(); it!=v.end(); it++)
	{
		std::cout << it->first << " ";
		it->second.show();
	 }
    std::cout << "---------------------------" << std::endl;

     std::cout << "--------部门信息------------" << std::endl;
     //研发部
     std::cout << "研发部：" << m.count(0) << "人。" << std::endl;
     std::multimap<int, Work>::iterator it = m.find(0);
     if ( it == m.end())
     {
        std::cout << "此部门无人！" << std::endl;
        return;
     }

     for(int i=0; i<m.count(0); i++)
     {
         
         it->second.show();
         it++;
     }

    std::cout << "---------------------------" << std::endl;
     //美术部：
     std::cout << "美术部：" << m.count(1) << "人。" << std::endl;
     std::multimap<int, Work>::iterator it_1 = m.find(1);
     if ( it == m.end())
     {
        std::cout << "此部门无人！" << std::endl;
        return;
     }

     for(int i=0; i<m.count(1); i++)
     {

         it_1->second.show();
         it_1++;
     }
    std::cout << "---------------------------" << std::endl;
    //管理部：
     std::cout << "管理部：" << m.count(2) << "人。" << std::endl;
     std::multimap<int, Work>::iterator it_2 = m.find(2);
     if ( it_2 == m.end())
     {
        std::cout << "此部门无人！" << std::endl;
        return;
     }
     for(int i=0; i<m.count(2); i++)
     {
         it_2->second.show();
         it_2++;
     }
     return;
 }