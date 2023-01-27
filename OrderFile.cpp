//
// Created by Administrator on 2023/1/27.
//


#include "OrderFile.h"

OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date; //日期
    string interval; //时间段
    string stuId; //学生编号
    string stuName; //学生姓名
    string roomId; //机房编号
    string status; //预约状态

    this->m_Size = 0; //记录预约个数
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {

        string key;
        string value;
        map<string, string> m;

        int pos = date.find(":"); // 4
        if (pos != -1) {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1

            m.insert(make_pair(key, value));
        }

        //cout << "key = " << key << endl;
        //cout << "value = " << value << endl;

        pos = interval.find(":"); // 4
        if (pos != -1) {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
            m.insert(make_pair(key, value));
        }

        pos = stuId.find(":"); // 4
        if (pos != -1) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
            m.insert(make_pair(key, value));
        }

        pos = stuName.find(":"); // 4
        if (pos != -1) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
            m.insert(make_pair(key, value));
        }

        pos = roomId.find(":"); // 4
        if (pos != -1) {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
            m.insert(make_pair(key, value));
        }

        pos = status.find(":"); // 4
        if (pos != -1) {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
            m.insert(make_pair(key, value));
        }


        this->m_orderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;


    }
    ifs.close();
}

void OrderFile::updateOrder() {

}
