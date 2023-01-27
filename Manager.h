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
#include <vector>
#include "GlobalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "algorithm"
#include "ComputerRoom.h"

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
    vector<Student> vStu;

    //教师容器
    vector<Teacher> vTea;

    //去重
    bool checkRepeat(int id, int type);

    //机房容器
    vector<ComputerRoom> vCom;

    void clearFile();
};


#endif //MACHINE_ROOM_RESERVATION_MANAGER_H
