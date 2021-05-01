/*
�ж�һ�������Ƿ��л���
�ҵ�һ���л�������Ļ���ڡ�
*/

// ����һ����ָ���һ����ָ�룬��ָ��һ����һ����ָ��ÿ����2����
// ����ָ��Ϳ�ָ���������������л���

#include <iostream>

bool link_ring(Link* link)
{
    Link* quick = link;
    Link* slow = link;

    while ( quick!= NULL && slow!=NULL )
    {
        quick = quick->pNext->pNext; //ָ����һ������һ��
        slow = slow->pNext;          //ָ����һ��

        if ( quick == slow )
        {
            return true; //�л���������
        }
    }
    return false; //�޻������ؼ�
}

Link* ring_entr(Link* link)
{
    Link* quick = link;
    Link* slow = link;

    while ( quick!= NULL && slow!=NULL )
    {
        quick = quick->pNext->pNext; 
        slow = slow->pNext;          

        if ( quick == slow ) //�л�
        {
            quick = link; //��ָ�뷵�������ͷָ��
            while ( quick != slow ) //������ָ���ٴ������������
            {
                quick = quick->pNext; 
                slow = slow->pNext;  
            }
            return quick;
        }
    }
    return NULL; //�޻�
}