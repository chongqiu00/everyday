//��45����Cherno C++�������֡�C++�ĸ����뿽�����캯��

#include <iostream>
#include <string.h>
class String
{
    private:
    char* m_Buffer;
    unsigned int m_Size;

    public:
    String( const char* string)  //Ĭ�Ͽ���
    {
         std::cout << "����" << std::endl;
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size + 1);
        m_Buffer[m_Size] = '\0';
    }

    String(const String& other) //���
    : m_Size(other.m_Size)
    {
        std::cout << "����" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size+1);
    }

    ~String() //�ͷŶ����ڴ�����
    {
        std::cout << "�ͷ�" << std::endl;
        if ( m_Buffer != NULL)
        {
            delete [] m_Buffer;
            m_Size = 0;
        } 
    }

    String& operator=(const String& other) //����=
    {
         std::cout << "����" << std::endl;
        m_Size = other.m_Size;
        delete [] m_Buffer;
        m_Buffer = new char[m_Size+1];
        memcpy(m_Buffer, other.m_Buffer, m_Size+1);
        return *this;
    }

    char& operator[](unsigned int index) //����[]
    {
        return m_Buffer[index];
    }



    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

//void Print( String str)//����д�����һ�����������ᴴ��һ��String�����뿪��������󣬼����ͷš�
                        //����������֪ʶ��ȡ�ִ���Ϣ�������ı��ִ����ݣ�ʹ�����ü��ɡ�
void Print(const String& str)                        
{
    std::cout << str << std::endl;
}

int main(int argc, char* argv[])
{
    String string = "zww";
    String str_1("zww");
    String str_2 = string;
    std::cout << string << std::endl;
    std::cout << str_1 << std::endl;
    std::cout << str_2 << std::endl;
    std::cout << "----------------------------------------" <<std::endl;
    Print(string);
    Print(str_1);
    Print(str_2);
    return 0;
}