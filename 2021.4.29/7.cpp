#include <stdio.h>
/*
���ûɶ����
*/
double fun(double h)
{
    if ( h <= 10 )
    {
        return (h*2.5);
    }
    else
    {
        int temp = (int) h;//ǿתΪint,���Խ�ȡ��h���������֡�
        if ( (h-(double)temp) == 0 )//��һ��������
                                    //����Ҫƥ���������ͣ��ͽ�tempǿתΪdouble�ˡ�
        {
            return 25+1.5*(h-10);
        } 
        else//�������������Զ���һ
        {
            return 25+1.5*(temp-10+1);
        }
    }
}
int main()
{
   printf("%lf",fun(22.3) );


    return 0;
}