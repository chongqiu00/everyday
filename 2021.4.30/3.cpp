/*��ʾ���ú���ʽ����*/

#include <iostream>

class Text_1
{
    public:
    Text_1(int number)
    {
        std::cout << number << std::endl;
    }

};

class Text_2
{
    public:
    explicit Text_2(int number) //������ʽ���á�
    {
        std::cout << number << std::endl;
    }
};
int main()
{
    Text_1 t_1 = 10; //֧����ʾ��ʽ����
    Text_1 t_2(10);

    //Text_2 t_3 = 10; //��֧����ʽ����
    Text_2 t_4(10); //֧����ʾ���á�
    return 0;
}