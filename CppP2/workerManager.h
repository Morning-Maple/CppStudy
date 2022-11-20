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

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"  //宏定义一个文件名

class WorkerManager{    //创建管理类
public:
    WorkerManager();    //构造函数

    void OutOfRange();  //选择范围外

    void Show_Menu();  //菜单

    void ExitSystem();  //退出系统

    int m_EmpNum;   //职工人数

    Worker ** m_EmpArray; //职工数组指针

    void Add_Emp(); //增加员工

    void save();    //保存文件

    bool m_FileIsEmpty; //判断文件是否为空的标志

    int get_EmpNum(); //统计文件中的人数

    void init_Emp();    //初始化员工

    void Show_Emp();    //显示职工

    void Del_Emp();     //删除职工

    int IsExist(int id);    //判断是否存在指定职工

    void Mod_Emp();         //修改职工

    void Find_Emp();    //查找职工

    void Sort_Emp();    //排序

    void Clean_File();  //清空文件

    ~WorkerManager();   //析构函数
};