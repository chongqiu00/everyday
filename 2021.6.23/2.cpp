//friend
#include <iostream>
#include <string>

class Room;
class other{
    public:
    other();

    //void visit_1();
    void visit_2();

    private:
    Room* room;
};
class Room{
    public:
    //��Ԫ
    friend void visit(Room* room);//ȫ�ֺ���

    //friend void other::visit_1();//���еĳ�Ա����

    friend class other; //��

    Room(){};

    Room(std::string woshi, std::string keting);
    std::string m_keting;

    private:
    std::string m_woshi;
};

other::other(){
    Room* room = new Room();
}

// void other::visit_1(){
//     std::cout << "���еĳ�Ա�����ڷ���room��˽�г�Ա" << room->m_woshi << std::endl;
//     return;
// }

void other::visit_2(){
    std::cout << "���ڷ���room��˽�г�Ա" << room->m_woshi << std::endl;
    return;
}

Room::Room(std::string woshi, std::string keting)
:m_woshi(woshi), m_keting(keting){}


void visit(Room* room){
    std::cout << "ȫ�ֺ����ڷ���room��˽�г�Ա" << room->m_woshi << std::endl;
    return;
}



int main()
{
    other other;
    Room room("����", "����");
    Room* p = &room;
    visit(p);
   // other.visit_1();
    other.visit_2();
    
    return 0;
}