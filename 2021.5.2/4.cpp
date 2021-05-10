//【55】【Cherno C++】【中字】C++的宏

#include <iostream>
#include <string>

// //1. 简单使用
// #define OPEN_CURLY {

// int main(int argc, char* argv[])
// OPEN_CURLY
//     std::cin.get();
// }

// //2. 宏换行使用
// #define MAIN int main(int argc, char* argv[]) \
// {\
//     std::cout << "zww" << std::endl; \
// }
// MAIN

// 3. 不同情况输出
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