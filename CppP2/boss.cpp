//
// Created by Morning_Maple on 2022.11.17.
//

#include "boss.h"

//构造函数——初始化id，名字，岗位编号
Boss::Boss(int id, string name, int dId){
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}
//显示个人信息
void Boss::showInfo(){
    cout << "职工编号：" << this->m_ID
         << "\t职工姓名：" << this->m_Name
         << "\t职工岗位：" << this->getDeptName()
         << "\t岗位职责：摸它一整天的鱼！" << endl;
}
//获取岗位名称
string Boss::getDeptName(){
    return string("老板");  //转换为字符串类型
}
