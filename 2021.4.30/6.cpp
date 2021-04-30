#pragma once

#include <iostream>
template<class T>
class Array
{
    public:
    Array(const int capacity = 0); //默认
    Array(const Array& array); //拷贝
    ~Array();

    Array& operator=(const Array& arry);  //重载=
	void Push_back(const T & val);        //尾插法
	void Pop_back();                 //尾删法
	int getCapacity();               //获取数组容量
	int	getSize();                   //获取数组大小

    private:
    T* m_array;
    int m_size;
    int m_capacity;
};

//默认
template<class T>
Array<T>::Array(const int capacity)
{
    if (capacity==0)
    {
        this->m_array = NULL;
        this->m_size = 0;
        this->m_capacity = 0;
    }
    else
    {
        this->m_array = new T[capacity];
        this->m_size = 0;
        this->m_capacity = capacity;
    }
}

//拷贝
template<class T>
Array<T>::Array(const Array& array)
{
    //清空原有数据
    this->m_array = new T[array.m_capacity];
    this->m_size = array.m_size;
    this->m_capacity = array.m_capacity;
    
    //拷贝
    for ( int i=0; i<array.m_size; i++)
    {
        this->m_array[i] = array.m_array[i];
    }
}

//这里注意防止浅拷贝，要释放原来的堆区内存数据。
template<class T>
Array<T>& Array<T>::operator= (const Array& array)
{
    if ( this->m_array != NULL )
    {
        delete [] m_array;
        this->m_capacity = 0;
        this->m_size = 0;
    }
    //清空原有数据
    this->m_array = new T[array.m_capacity];
    this->m_size = array.m_size;
    this->m_capacity = array.m_capacity;
    //拷贝
    for ( int i=0; i<array.m_size; i++)
    {
        this->m_array[i] = array.m_array[i];
    }

    return this*;
}

//尾插法
template<class T>
void Array<T>::Push_back(const T & val)
{
    if ( this->m_capacity == this->m_size ) //扩容
    {
        NewArray = new T[this->m_capacity + 2];
        for ( int i=0; i<this->m_size; i++)
        {
            NewArray[i] = this->m_array[i];
        }
        delete [] this->m_array;
        this->m_array = NewArray;
    }

    this->m_array[this->m_size] = val;
    this->m_size ++;
}

//尾删法
template <class T>
void Array<T>::Pop_back()      
{
    if (this->m_size == 0)
	{
		return;
	}
    this->m_size --;
}           

//获取数组容量
template<class T>
int Array<T>::getCapacity()
{
    return this->m_capacity;
}     

template<class T>
int Array<T>::getSize()
{
    return this->m_size;
}
	