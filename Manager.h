//
// Created by Administrator on 2023/1/19.
//

#ifndef MACHINE_ROOM_RESERVATION_MANAGER_H
#define MACHINE_ROOM_RESERVATION_MANAGER_H

#include <iostream>

using namespace std;

#include "Identity.h"
#include <string>
#include <fstream>
#include "GlobalFile.h"
class Manager : public Identity {
public:

    //默认构造
    Manager();

    //有参构造
    Manager(string name, string pwd);

    //选择菜单
    virtual void operMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void cleanFile();

    //初始化容器
    void initVector();

    //学生容器


};


#endif //MACHINE_ROOM_RESERVATION_MANAGER_H
