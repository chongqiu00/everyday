//【47】【Cherno C++】【中字】C++的动态数组（std::vector）
#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) //重载<<操作符
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

    //for ( Vertex v : vertices ) //这样写会将v整 个复制 格式：for( 传入容器中的参数名 v : 容器名)
    for (const Vertex& v : vertices ) //传入引用就不会复制
    {
        std::cout << v << std::endl;
    }

    return 0;
}