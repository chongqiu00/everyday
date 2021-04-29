#include <iostream>

class E
{
    public:
    static const int size = 5;
    int arry[size];

    E()
    {
        for (int i=0; i<5; i++)
        {
            arry[i] = 2;
        }
    }
};
int main()
{
    return 0;
}