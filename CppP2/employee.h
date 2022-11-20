//
// Created by Morning_Maple on 2022.11.16.
//
//#pragma once不管用注释后，调用下面四行解决
//#ifndef CPPP2_EMPLOYEE_H
//#define CPPP2_EMPLOYEE_H
//
//#endif //CPPP2_EMPLOYEE_H

#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//子表1
//员工
class Employee : public Worker{
public:
    //构造函数
    Employee(int id, string name, int dId); //初始化id，名字，岗位编号
    //显示个人信息
    virtual void showInfo();
    //获取岗位名称
    virtual string getDeptName();
};