/*ʵ��һ���Լ���String����һ������C++����֪ʶ�ĺ��⡣
����Ҫ��ʵ�����£����캯���������������������캯��(copy constructor)�����ظ�ֵ������(copy assignment operator)����
*/

#include <iostream>
#include <string>
#include <string.h>

class MyString
{
    public:

    MyString(const char* str = nullptr); //Ĭ�Ϲ��캯��
    MyString(const MyString* str); // �������캯��
    ~MyString();        //�ͷŶ����ڴ档

    //����ʵ��
    MyString* operator= (const MyString * str);//����==

    char* find(char ch); //�����ִ��е����ݡ�
    char* find(char* str); //�����ִ��е��ִ���

    //���ʽӿ�
    int size(); //ȡ���ִ���С��
    char* get_str(); //ȡ���ִ�

    private:
    char *m_Array;
    int m_Size;

};

//�ͷŶ����ڴ档
MyString::~MyString()
{
    if ( m_Array != nullptr )
    {
        delete [] m_Array;
        m_Size = 0;
    }
}

//Ĭ�Ϲ��캯��
MyString::MyString(const char* str) //string str; string str("zww");
{
    if ( str == nullptr ) //���ַ�����
    {
        m_Array = new char[1];//��Ž����ַ���
        *m_Array = '\0'; 
        m_Size = 0; 
    }
    else
    {
        int i = 0, num = 1;
        char* p_str = (char*) str; //���ڱ�����
        while ( *p_str != '\0' )
        {
            num++;
            p_str++;
        }
        m_Size = num;
        m_Array = new char[m_Size]; //�����ڴ��С
        p_str = (char*) str;
        while ( *p_str != '\0') //��ֵճ��
        {
            m_Array[i] = *p_str;
            i++;
            p_str++;
        }
        m_Array[i] = '\0'; //������ 
    }
}

// �������캯�� 
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
        m_Array[i] = '\0'; //������
     }
    
}

//����=
MyString* MyString::operator= (const MyString * str) //string str = str_2
{
    if (this->m_Array == NULL)
    {
        return this;
    }
    else
    {
        int num = 1, i = 0;
        //�������
        delete [] this->m_Array;
        this->m_Array = NULL;
        this->m_Size = 0;
        //��ʼ������
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

//�����ִ��е����ݡ�
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

//ȡ���ִ���С��
int MyString::size()
{
    return m_Size;
} 
//ȡ���ִ�
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
    printf("�ҵ�%c\n", *p);

    // printf("str=%s\n", str.m_Array);
    // printf("str_1=%s\n", str_1.m_Array);
    //  printf("str_2=%s\n", str_2.m_Array);

    
    return 0;
}