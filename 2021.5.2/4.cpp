//��55����Cherno C++�������֡�C++�ĺ�

#include <iostream>
#include <string>

// //1. ��ʹ��
// #define OPEN_CURLY {

// int main(int argc, char* argv[])
// OPEN_CURLY
//     std::cin.get();
// }

// //2. �껻��ʹ��
// #define MAIN int main(int argc, char* argv[]) \
// {\
//     std::cout << "zww" << std::endl; \
// }
// MAIN

// 3. ��ͬ������
#define PR_DEBUG 1

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl

#else
#deifne LOG(x)

#endif

int main(int argc, char* argv[])
{
    LOG("Hello");

    std::cin.get();
    return 0;
}