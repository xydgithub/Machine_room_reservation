#include <iostream>

using namespace std;

#include "GlobalFile.h"
#include "Identity.h"
#include "fstream"
#include "string"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"


void managerMenu(Identity *&manager) {
    while (1) {
        //管理员菜单
        manager->operMenu();

        Manager *man = (Manager*)manager;

        int select = 0;

        cin >> select;

        if (select == 1) { //添加账号
            cout << "添加账号" <<endl;
            man->addPerson();
        } else if (select == 2) { //查看账号
            cout << "查看账号" <<endl;
            man->showPerson();
        } else if (select == 3) { //查看机房
            cout << "查看机房" <<endl;
            man->showPerson();
        } else if (select == 4) { //清空预约
            cout << "清空预约" << endl;
            man->cleanFile();
        } else {
            delete manager;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void LoginIn(string filename, int type) {
    Identity *person = nullptr;

    ifstream ifs; //读文件
    ifs.open(filename, ios::in);

    //文件不存在时
    if (!ifs.is_open()) {
        cout << "文件不存在" <<endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;


    if (type == 1) { //学生登录
        cout << "请输入你的学号" << endl;
        cin >> id;
    } else if (type == 2) { //教师登录
        cout << "请输入你的职工号" <<endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码：" <<endl;
    cin >> pwd;

    if (type == 1) {
        //学生登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "学生验证登录成功！" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);

                return;
            }

        }
    } else if (type == 2) {
        //教师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "教师验证登录成功！" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);



                return;
            }

        }
    } else if (type == 3) {
        //管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {
            if (name == fName && pwd == fPwd) {
                cout << "管理员验证登录成功！" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);

                //进入管理员子菜单界面
                managerMenu(person);
                return;
            }

        }
    }

    cout << "验证登录失败！" << endl;

    system("pause");
    system("cls");
    return;

}

void test01() {
    ofstream out("arrin.txt");
    if (out.is_open())
    {
        out << "This is a line.\n";
        out << "This is another line.\n";
        out.close();
    }


}
int main() {
    int select = 0;
    while (1) {
        cout << "============= 欢迎来到机房预约系统 =============" << endl;
        cout << "请输入您的身份" << endl;
        cout << "1、学生代表" << endl;
        cout << "2、老师" << endl;
        cout << "3、管理员" << endl;
        cout << "0、退出" << endl;
        cout << "请输入您的选择：" << endl;

        cin >> select;

        switch (select) {
            case 1: //学生
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2: //老师
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3: //管理员
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0: //退出系统
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break;
            default:
                cout << "输入有误，请重新选择！" << endl;
                system("pause");
                system("cls");
                break;
        }
    }


}




