//
// Created by Administrator on 2023/1/19.
//

#ifndef MACHINE_ROOM_RESERVATION_TEACHER_H
#define MACHINE_ROOM_RESERVATION_TEACHER_H
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include "vector"
#include "OrderFile.h"

class Teacher : public Identity {
public:

    //默认构造
    Teacher();

    //有参
    Teacher(int empId, string name, string pwd);

    //菜单页面
    virtual void operMenu();


    //查看所有预约
    void showAllOrder();


    //审核预约
    void validOrder();

    int m_EmpId; //教师编号
};


#endif //MACHINE_ROOM_RESERVATION_TEACHER_H
