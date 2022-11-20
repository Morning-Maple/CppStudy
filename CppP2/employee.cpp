//
// Created by Morning_Maple on 2022.11.16.
//

#include "employee.h"

//构造函数——初始化id，名字，岗位编号
Employee::Employee(int id, string name, int dId){
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}
//显示个人信息
void Employee::showInfo(){
    cout << "职工编号：" << this->m_ID
        << "\t职工姓名：" << this->m_Name
        << "\t职工岗位：" << this->getDeptName()
        << "\t岗位职责：好好干活，不准摸鱼！" << endl;
}
//获取岗位名称
string Employee::getDeptName(){
    return string("员工");  //转换为字符串类型
}