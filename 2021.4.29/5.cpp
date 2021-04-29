#include <iostream>
#include <string>

void fun( const std::string& str)
{
    std::cout << str <<std::endl;
}
int main()
{
  std::string str = "zww";
  fun(str);

  std::cout << str <<std::endl;

}