//��47����Cherno C++�������֡�C++�Ķ�̬���飨std::vector��
#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) //����<<������
{
    stream << vertex.x << "," << vertex.y << "," << vertex.z << std::endl;
    return stream;
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});

    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }

    //for ( Vertex v : vertices ) //����д�Ὣv�� ������ ��ʽ��for( ���������еĲ����� v : ������)
    for (const Vertex& v : vertices ) //�������þͲ��Ḵ��
    {
        std::cout << v << std::endl;
    }

    return 0;
}