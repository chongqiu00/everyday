//³õÊ¼Ä£¿é
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void MyPrint(int val){
    std::cout << val << " ";
}
int main(int argc, char* argv[])
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    std::vector<int>::iterator pBegin = v.begin();
    std::vector<int>::iterator pEnd = v.end();

    while ( pBegin != pEnd ){
        std::cout << *pBegin << " ";
        pBegin++;
    }
    std::cout << std::endl;
    for (std::vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for_each(v.begin(), v.end(), MyPrint);

    return 0;
}