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
    //友元
    friend void visit(Room* room);//全局函数

    //friend void other::visit_1();//类中的成员函数

    friend class other; //类

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
//     std::cout << "类中的成员函数在访问room的私有成员" << room->m_woshi << std::endl;
//     return;
// }

void other::visit_2(){
    std::cout << "类在访问room的私有成员" << room->m_woshi << std::endl;
    return;
}

Room::Room(std::string woshi, std::string keting)
:m_woshi(woshi), m_keting(keting){}


void visit(Room* room){
    std::cout << "全局函数在访问room的私有成员" << room->m_woshi << std::endl;
    return;
}



int main()
{
    other other;
    Room room("卧室", "客厅");
    Room* p = &room;
    visit(p);
   // other.visit_1();
    other.visit_2();
    
    return 0;
}