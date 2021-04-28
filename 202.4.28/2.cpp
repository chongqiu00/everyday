/*
���ڣ�2021��4��28
�༭�ˣ�chongqiu00
˵����vector, multimap�����ʹ�á�
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <ctime>

/*
- ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
- Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
- �����10��Ա�����䲿�ź͹���
- ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
- �ֲ�����ʾԱ����Ϣ
*/

class Work
{
    public:
    Work(std::string name)
    : m_Name(name){}

    void show()
    {
        std::cout << m_Name << "���ʣ�" << m_Salary << std::endl; 
    }

    std::string m_Name;
    int m_Salary;
};

class Print
{
    public:
    void operator() (Work &w)
    {
        std::cout << w.m_Name << "���ʣ�" << w.m_Salary << "Ԫ" << std::endl; 
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



//��ʼ��10��Ա�������������
void CreateWork(std::vector<Work>& v);

//��Ա����Ϣ��multimap�����У�Ա�����ű����Ϊ���ֵ��
void InputMap(std::vector<Work>& v, std::multimap<int, Work>& m);

//�����������ʾ
void show(std::multimap<int, Work>& m);

int main(int argc, char* argv[])
{
    srand((unsigned int)time(NULL));
    std::vector<Work> v;
    std::multimap<int, Work> m;

    //����10��Ա������
    CreateWork(v);
    //for_each(v.begin(), v.end(), Print());

    //�����Ա��������map����
    InputMap(v, m);

    //�����������ʾ
    show(m);

    return 0;
}

//��ʼ��10��Ա�������������
void CreateWork(std::vector<Work>& v)
{
    char idx[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'K'};
    for (int i=0; i<10; i++)
    {
        std::string name = "Ա��";
        name += idx[i];
        Work w(name);
        w.m_Salary = rand() % 100000 + 5000;
        v.push_back(w);
    }
}

//��Ա����Ϣ��multimap�����У�Ա�����ű����Ϊ���ֵ��
void InputMap(std::vector<Work>& v, std::multimap<int, Work>& m)
{
    for (std::vector<Work>::iterator it=v.begin(); it!=v.end(); it++)
    {
        int depart = rand() % 3;//����0��1��2���������
        //0���з��� 1�������� 2������
        m.insert(std::pair<int, Work>(depart, *it));
    }
}

//�����������ʾ
 void show(std::multimap<int, Work>& m)
 {
     
    std::vector<std::pair<int, Work>> v(m.begin(), m.end());//��map�е�Ԫ�ؿ�����vector��
	std::sort(v.begin(),v.end(),Compare());//ʵ��value������

    std::cout << "-------����������ʾ-----------" << std::endl;
	for (std::vector<std::pair<int, Work>>::iterator it=v.begin(); it!=v.end(); it++)
	{
		std::cout << it->first << " ";
		it->second.show();
	 }
    std::cout << "---------------------------" << std::endl;

     std::cout << "--------������Ϣ------------" << std::endl;
     //�з���
     std::cout << "�з�����" << m.count(0) << "�ˡ�" << std::endl;
     std::multimap<int, Work>::iterator it = m.find(0);
     if ( it == m.end())
     {
        std::cout << "�˲������ˣ�" << std::endl;
        return;
     }

     for(int i=0; i<m.count(0); i++)
     {
         
         it->second.show();
         it++;
     }

    std::cout << "---------------------------" << std::endl;
     //��������
     std::cout << "��������" << m.count(1) << "�ˡ�" << std::endl;
     std::multimap<int, Work>::iterator it_1 = m.find(1);
     if ( it == m.end())
     {
        std::cout << "�˲������ˣ�" << std::endl;
        return;
     }

     for(int i=0; i<m.count(1); i++)
     {

         it_1->second.show();
         it_1++;
     }
    std::cout << "---------------------------" << std::endl;
    //������
     std::cout << "������" << m.count(2) << "�ˡ�" << std::endl;
     std::multimap<int, Work>::iterator it_2 = m.find(2);
     if ( it_2 == m.end())
     {
        std::cout << "�˲������ˣ�" << std::endl;
        return;
     }
     for(int i=0; i<m.count(2); i++)
     {
         it_2->second.show();
         it_2++;
     }
     return;
 }