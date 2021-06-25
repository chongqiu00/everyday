//类模块与友元
#include <iostream>
template<class T>
void show(M<T> m);

template<class T>
class M{
public:
    M(){}
    M(T a)
    :m_a(a){}
    friend void show<>(M<T> m);
private:
    T m_a;
};

//全局类外实现。
template<class T>
void show(M<T> m){
    std::cout << m.m_a << std::endl;
    return;
}
int main(int argc, char* argv[])
{
    return 0;
}