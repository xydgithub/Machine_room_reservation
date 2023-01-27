//
// Created by Administrator on 2023/1/19.
//

#include <fstream>
#include "Student.h"

Student::Student() {

}

Student::Student(int id, string name, string pwd) {

    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
        vCom.push_back(c);
    }

    ifs.close();

}

void Student::operMenu() {
    cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
    cout << "1、申请预约" << endl;
    cout << "2、查看我的预约" << endl;
    cout << "3、查看所有预约" << endl;
    cout << "4、取消预约" << endl;
    cout << "0、注销登录" << endl;
    cout << "请选择您的操作" << endl;
}

void Student::applyOrder() {
    cout << "机房开放时间为周一至周五" << endl;
    cout << "请输入申请预约的时间" << endl;
    cout << "1、周一" << endl;
    cout << "2、周二" << endl;
    cout << "3、周三" << endl;
    cout << "4、周四" << endl;
    cout << "5、周五" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;


    }

    cout << "请输入申请预约时间段" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;

    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <=2) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1号机房容量" << vCom[0].m_MaxNum << endl;
    cout << "2号机房容量" << vCom[1].m_MaxNum << endl;
    cout << "3号机房容量" << vCom[2].m_MaxNum << endl;

    while (true) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout <<"预约成功，审核中！" << endl;

    ofstream ofs(ORDER_FILE, ios::app);

    ofs << "data:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();

    system("pause");
    system("cls");

}

void Student::showMyOrder() {
    OrderFile of;

}

void Student::showAllOrder() {

}

void Student::cancelOrder() {

}
