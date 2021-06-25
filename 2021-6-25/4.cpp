#include <iostream>

template<class T>
class Father{
public:
    Father(){}
    Father(T a)
    : m_a(a){}

    T m_a;
};

template<class S, class T>
class Son:public Father<T>{
public:
    Son(S b)
    : m_b(b){}

    S m_b;
};

int main(int argc, char* argv[]){
    Father<int> i_1(1);
    std::cout << i_1.m_a  << std::endl;

    Son<char, int> i_2('A');
    i_2.m_a = 12;
    std::cout << i_2.m_a << i_2.m_b << std::endl;
    return 0;
}