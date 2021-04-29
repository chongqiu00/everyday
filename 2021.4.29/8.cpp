#include <iostream>
/*字符串字面量*/
int main(int argc, char* argv[])
{
    const char* str_1 = "zww";
    //char* str_1 = "zww"; //错误。

    char str_2[] = "zww";
    str_2[1] = 'z';

    std::cout << "str_1:" << str_1 << std::endl;
    std::cout << "str_2:" << str_2 << std::endl;

    const char* str_3 = u8"mmm"; //一个字节 utf8
    const wchar_t* str_4 = L"mmm"; //两个字节
    const char16_t* str_5 = u"mmm"; //两个字节 utf16
    const char32_t* str_6 = U"mmm"; //四个字节 utf32

    std::cout << "str_3:" << str_3 << std::endl;
    std::cout << "str_4:" << str_4 << std::endl;
    std::cout << "str_5:" << str_5 << std::endl;
    std::cout << "str_6:" << str_6 << std::endl;

    using namespace std::string_literals;
    std::u32string name0 = U"zww"s + U" hello";

    const char* example = R"(Line1
    Line2
    Line3
    Line4)"; //R忽略转义字符。

    //std::cout << "name0:" << Uname0 <<std::endl;
    std::cout << "example:" << example <<std::endl;



    return 0;
}