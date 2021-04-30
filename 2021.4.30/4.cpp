/*实现一个自己的String类是一道考验C++基础知识的好题。
至少要能实现以下：构造函数，析构函数，拷贝构造函数(copy constructor)，重载赋值操作符(copy assignment operator)，。
*/

#include <iostream>
#include <string>
#include <string.h>

class MyString
{
    public:

    MyString(const char* str = nullptr); //默认构造函数
    MyString(const MyString* str); // 拷贝构造函数
    ~MyString();        //释放堆区内存。

    //功能实现
    MyString* operator= (const MyString * str);//重载==

    char* find(char ch); //查找字串中的内容。
    char* find(char* str); //查找字串中的字串。

    //访问接口
    int size(); //取得字串大小。
    char* get_str(); //取得字串

    private:
    char *m_Array;
    int m_Size;

};

//释放堆区内存。
MyString::~MyString()
{
    if ( m_Array != nullptr )
    {
        delete [] m_Array;
        m_Size = 0;
    }
}

//默认构造函数
MyString::MyString(const char* str) //string str; string str("zww");
{
    if ( str == nullptr ) //无字符传入
    {
        m_Array = new char[1];//存放结束字符。
        *m_Array = '\0'; 
        m_Size = 0; 
    }
    else
    {
        int i = 0, num = 1;
        char* p_str = (char*) str; //用于遍历。
        while ( *p_str != '\0' )
        {
            num++;
            p_str++;
        }
        m_Size = num;
        m_Array = new char[m_Size]; //开辟内存大小
        p_str = (char*) str;
        while ( *p_str != '\0') //赋值粘贴
        {
            m_Array[i] = *p_str;
            i++;
            p_str++;
        }
        m_Array[i] = '\0'; //结束符 
    }
}

// 拷贝构造函数 
MyString::MyString(const MyString* str)  //string str_1(str_2);
{
    if (str == NULL)
    {
        m_Array = NULL;
    }
    else
    {
        int num=1, i=0;
        char* p_str = (char*) str;
        //m_Size = strlen(str) + 1;
        while ( *p_str != '\0' )
        {
            num++;
        }
        p_str = (char*) str;
        m_Array = new char[num];
        while ( *p_str != '\0' )
        {
            m_Array[0] = *p_str;
            i++;
            p_str++;
        }
        m_Array[i] = '\0'; //结束符
     }
    
}

//重载=
MyString* MyString::operator= (const MyString * str) //string str = str_2
{
    if (this->m_Array == NULL)
    {
        return this;
    }
    else
    {
        int num = 1, i = 0;
        //清空数据
        delete [] this->m_Array;
        this->m_Array = NULL;
        this->m_Size = 0;
        //开始拷贝。
        char* p_str = (char*) str;
        while ( *p_str != '\0' )
        {
            num++;
        }
        p_str = (char*) str;
        while ( *p_str != '\0')
        {
            this->m_Array[i] = *p_str;
            i++;
            p_str++;
        }
        this->m_Array[i] = '\0';
        return this;
    }
}

//查找字串中的内容。
char* MyString::find(char ch)
{
    int i=0;
    if ( m_Array == NULL )
    {
        return NULL;
    }
    else
    {
        char* p = (char*) m_Array;
       for (; i<m_Size; i++)
       {
           if ( *p == ch )
           {
               break;
           }
           p++;
       }
       if ( i == m_Size )
       {
           return NULL;
       }
       else
       {
           return p;
       }

    }
}

//取得字串大小。
int MyString::size()
{
    return m_Size;
} 
//取得字串
char* MyString::get_str()
{
    return m_Array;
}


int main(int argc, char* argv[])
{
    MyString str("zfugjkdhm");

    MyString str_1(str);

    MyString str_2 = str;

    char* p;

    p = str.find('f');
    printf("找到%c\n", *p);

    // printf("str=%s\n", str.m_Array);
    // printf("str_1=%s\n", str_1.m_Array);
    //  printf("str_2=%s\n", str_2.m_Array);

    
    return 0;
}