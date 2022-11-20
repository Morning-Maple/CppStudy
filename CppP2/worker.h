//
// Created by Morning_Maple on 2022.11.16.
//
//#pragma once不管用注释后，调用下面四行解决
//#ifndef CPPP2_WORKERMANAGER_H
//#define CPPP2_WORKERMANAGER_H
//
//#endif //CPPP2_WORKERMANAGER_H

#pragma once
#include <iostream>
using namespace std;
#include <string>

//总表
//职工抽象类，不用实现，不需要相对应的源文件
class Worker{
public:
    //显示个人信息
    virtual void showInfo() = 0;
    //获取岗位名称
    virtual string getDeptName() = 0;
    int m_ID;   //岗位编号
    string m_Name;  //姓名
    int m_DeptID;   //部门编号
};