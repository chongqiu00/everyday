/*ö��*/

#include <iostream>

enum A
{
    a, b, c, d   //����';'
};

int main(int vrgc, char* argv[])
{
    A A1;
    A1 = a;    
    std::cout << A1  << std::endl; // 0

    return 0;
}