#include <iostream>
/*�ַ���������*/
int main(int argc, char* argv[])
{
    const char* str_1 = "zww";
    //char* str_1 = "zww"; //����

    char str_2[] = "zww";
    str_2[1] = 'z';

    std::cout << "str_1:" << str_1 << std::endl;
    std::cout << "str_2:" << str_2 << std::endl;

    const char* str_3 = u8"mmm"; //һ���ֽ� utf8
    const wchar_t* str_4 = L"mmm"; //�����ֽ�
    const char16_t* str_5 = u"mmm"; //�����ֽ� utf16
    const char32_t* str_6 = U"mmm"; //�ĸ��ֽ� utf32

    std::cout << "str_3:" << str_3 << std::endl;
    std::cout << "str_4:" << str_4 << std::endl;
    std::cout << "str_5:" << str_5 << std::endl;
    std::cout << "str_6:" << str_6 << std::endl;

    using namespace std::string_literals;
    std::u32string name0 = U"zww"s + U" hello";

    const char* example = R"(Line1
    Line2
    Line3
    Line4)"; //R����ת���ַ���

    //std::cout << "name0:" << Uname0 <<std::endl;
    std::cout << "example:" << example <<std::endl;



    return 0;
}