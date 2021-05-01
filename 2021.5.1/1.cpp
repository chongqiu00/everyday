//【45】【Cherno C++】【中字】C++的复制与拷贝构造函数

#include <iostream>
#include <string.h>
class String
{
    private:
    char* m_Buffer;
    unsigned int m_Size;

    public:
    String( const char* string)  //默认拷贝
    {
         std::cout << "创建" << std::endl;
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size + 1);
        m_Buffer[m_Size] = '\0';
    }

    String(const String& other) //深拷贝
    : m_Size(other.m_Size)
    {
        std::cout << "创建" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size+1);
    }

    ~String() //释放堆区内存数据
    {
        std::cout << "释放" << std::endl;
        if ( m_Buffer != NULL)
        {
            delete [] m_Buffer;
            m_Size = 0;
        } 
    }

    String& operator=(const String& other) //重载=
    {
         std::cout << "创建" << std::endl;
        m_Size = other.m_Size;
        delete [] m_Buffer;
        m_Buffer = new char[m_Size+1];
        memcpy(m_Buffer, other.m_Buffer, m_Size+1);
        return *this;
    }

    char& operator[](unsigned int index) //重载[]
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

//void Print( String str)//这样写会产生一个副本，即会创建一个String对象，离开此作用域后，及被释放。
                        //在这里我们知识获取字串信息，而不改变字串内容，使用引用即可。
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