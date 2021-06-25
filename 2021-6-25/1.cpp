//模块Y隐式转换
/*
#include <iostream>

int main(int argc, char* argv[])
{
    return 0;
}
*/

#include <iostream>

template<typename T>
void fun(T a, T b){
    std::cout << a << b << std::endl;
    return;
}
int main(int argc, char* argv[]){
    int a = 0, b = 1;
    char c = 'a';
    //fun(a,c); 不可隐式转换
    fun<int>(a, c);
    return 0;
}