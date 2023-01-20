//
// Created by Administrator on 2023/1/19.
//

#ifndef MACHINE_ROOM_RESERVATION_STUDENT_H
#define MACHINE_ROOM_RESERVATION_STUDENT_H
#include <iostream>
#include "Identity.h"
using namespace std;

class Student : public Identity{
public:

    //默认构造
    Student();

    //有参构造
    Student(int id, string name, string pwd);

    //菜单页面
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看我的预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int m_Id;

};


#endif //MACHINE_ROOM_RESERVATION_STUDENT_H
