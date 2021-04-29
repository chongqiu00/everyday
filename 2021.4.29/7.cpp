#include <stdio.h>
/*
解答，没啥东西
*/
double fun(double h)
{
    if ( h <= 10 )
    {
        return (h*2.5);
    }
    else
    {
        int temp = (int) h;//强转为int,可以截取到h的整数部分。
        if ( (h-(double)temp) == 0 )//是一个整数，
                                    //两数要匹配数据类型，就将temp强转为double了。
        {
            return 25+1.5*(h-10);
        } 
        else//不是整数，就自动加一
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