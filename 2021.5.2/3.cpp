//48】【Cherno C++】【中字】C++的stdvector使用优化
#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(int x, int y, int z)
    : x(x), y(y), z(z)
    {
        std::cout << "复制" << std::endl;
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
    //注意，传入的是变量的参数列表。
    //尽可能多的使用emplace_back传入容器变量。
    v.emplace_back(11, 21, 31); //这个做了优化，避免反复的复制，但是编译器可能自己做了优化，与push_back的效果差不多。
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