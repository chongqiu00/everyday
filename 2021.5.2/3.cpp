//48����Cherno C++�������֡�C++��stdvectorʹ���Ż�
#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(int x, int y, int z)
    : x(x), y(y), z(z)
    {
        std::cout << "����" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    std::vector<Vertex> v;
    v.push_back(Vertex(11, 21, 31));
    v.push_back(Vertex(12, 22, 32));
    v.push_back(Vertex(13, 23, 33));
    v.push_back(Vertex(11, 21, 31));
    v.push_back(Vertex(12, 22, 32));
    v.push_back(Vertex(13, 23, 33));
    v.push_back(Vertex(11, 21, 31));
    v.push_back(Vertex(12, 22, 32));
    v.push_back(Vertex(13, 23, 33));
    v.push_back(Vertex(11, 21, 31));
    v.push_back(Vertex(12, 22, 32));
    v.push_back(Vertex(13, 23, 33));
    v.push_back(Vertex(11, 21, 31));
    v.push_back(Vertex(12, 22, 32));
    v.push_back(Vertex(13, 23, 33));

    std::cout << "---------------------------" << std::endl;
    //ע�⣬������Ǳ����Ĳ����б�
    //�����ܶ��ʹ��emplace_back��������������
    v.emplace_back(11, 21, 31); //��������Ż������ⷴ���ĸ��ƣ����Ǳ����������Լ������Ż�����push_back��Ч����ࡣ
    v.emplace_back(12, 22, 32);
    v.emplace_back(13, 23, 33);
    v.emplace_back(11, 21, 31);
    v.emplace_back(12, 22, 32);
    v.emplace_back(13, 23, 33);
    v.emplace_back(11, 21, 31);
    v.emplace_back(12, 22, 32);
    v.emplace_back(13, 23, 33);
    v.emplace_back(11, 21, 31);
    v.emplace_back(12, 22, 32);
    v.emplace_back(13, 23, 33);
    v.emplace_back(11, 21, 31);
    v.emplace_back(12, 22, 32);
    v.emplace_back(13, 23, 33);

    return 0;
}