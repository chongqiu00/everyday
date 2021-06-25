//
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string str = "zwr";

    int pos = str.find("r", 1);
    if ( -1 == pos ){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "pos=" << pos << std::endl;
    }
    str.replace(0, 3, "1234");
    std::cout << str << std::endl;

    return 0;
}