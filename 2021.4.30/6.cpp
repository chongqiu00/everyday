#pragma once

#include <iostream>
template<class T>
class Array
{
    public:
    Array(const int capacity = 0); //Ĭ��
    Array(const Array& array); //����
    ~Array();

    Array& operator=(const Array& arry);  //����=
	void Push_back(const T & val);        //β�巨
	void Pop_back();                 //βɾ��
	int getCapacity();               //��ȡ��������
	int	getSize();                   //��ȡ�����С

    private:
    T* m_array;
    int m_size;
    int m_capacity;
};

//Ĭ��
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

//����
template<class T>
Array<T>::Array(const Array& array)
{
    //���ԭ������
    this->m_array = new T[array.m_capacity];
    this->m_size = array.m_size;
    this->m_capacity = array.m_capacity;
    
    //����
    for ( int i=0; i<array.m_size; i++)
    {
        this->m_array[i] = array.m_array[i];
    }
}

//����ע���ֹǳ������Ҫ�ͷ�ԭ���Ķ����ڴ����ݡ�
template<class T>
Array<T>& Array<T>::operator= (const Array& array)
{
    if ( this->m_array != NULL )
    {
        delete [] m_array;
        this->m_capacity = 0;
        this->m_size = 0;
    }
    //���ԭ������
    this->m_array = new T[array.m_capacity];
    this->m_size = array.m_size;
    this->m_capacity = array.m_capacity;
    //����
    for ( int i=0; i<array.m_size; i++)
    {
        this->m_array[i] = array.m_array[i];
    }

    return this*;
}

//β�巨
template<class T>
void Array<T>::Push_back(const T & val)
{
    if ( this->m_capacity == this->m_size ) //����
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

//βɾ��
template <class T>
void Array<T>::Pop_back()      
{
    if (this->m_size == 0)
	{
		return;
	}
    this->m_size --;
}           

//��ȡ��������
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
	