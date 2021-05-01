/*
判断一个链表是否有环。
找到一个有环的链表的环入口。
*/

// 设置一个慢指针和一个快指针，慢指针一次走一步快指针每次走2步。
// 当慢指针和快指针相遇，此链表有环。

#include <iostream>

bool link_ring(Link* link)
{
    Link* quick = link;
    Link* slow = link;

    while ( quick!= NULL && slow!=NULL )
    {
        quick = quick->pNext->pNext; //指向下一个的下一个
        slow = slow->pNext;          //指向下一个

        if ( quick == slow )
        {
            return true; //有环，返回真
        }
    }
    return false; //无环，返回假
}

Link* ring_entr(Link* link)
{
    Link* quick = link;
    Link* slow = link;

    while ( quick!= NULL && slow!=NULL )
    {
        quick = quick->pNext->pNext; 
        slow = slow->pNext;          

        if ( quick == slow ) //有环
        {
            quick = link; //快指针返回链表的头指针
            while ( quick != slow ) //当两个指针再次相遇即是入口
            {
                quick = quick->pNext; 
                slow = slow->pNext;  
            }
            return quick;
        }
    }
    return NULL; //无环
}