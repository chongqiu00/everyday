//
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string str1="zww";
    std::string str2="12345";
    str1.append(str2, 2, 2);
    std::cout << str1 << std::endl;
    return 0;
}