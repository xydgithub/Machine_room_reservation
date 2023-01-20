//
// Created by Administrator on 2023/1/19.
//

#ifndef MACHINE_ROOM_RESERVATION_IDENTITY_H
#define MACHINE_ROOM_RESERVATION_IDENTITY_H
#include "iostream"
using namespace std;

class Identity {
public:

    //操作菜单，纯虚函数
    virtual void operMenu() = 0;

    string m_Name; //用户名
    string m_Pwd; //密码
};


#endif //MACHINE_ROOM_RESERVATION_IDENTITY_H

