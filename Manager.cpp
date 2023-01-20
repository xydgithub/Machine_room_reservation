//
// Created by Administrator on 2023/1/19.
//


#include "Manager.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;
}

void Manager::operMenu() {
    cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
    cout << "1、添加账号" << endl;
    cout << "2、查看账号" << endl;
    cout << "3、查看机房" << endl;
    cout << "4、清空预约" << endl;
    cout << "0、注销登录" << endl;
    cout << "请选择您的操作" << endl;
}

void Manager::addPerson() {
    cout << "请输入添加账号的类型：" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1) {
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
    } else {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
    }

    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout << tip << endl;

    cin >> id;

    cout << "请输入姓名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    system("pause");
    system("cls");

    ofs.close();
}

void Manager::showPerson() {

}

void Manager::showComputer() {

}

void Manager::cleanFile() {

}


