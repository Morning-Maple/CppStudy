//
// Created by Morning_Maple on 2022.11.16.
//
//#pragma once������ע�ͺ󣬵����������н��
//#ifndef CPPP2_EMPLOYEE_H
//#define CPPP2_EMPLOYEE_H
//
//#endif //CPPP2_EMPLOYEE_H

#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//�ӱ�1
//Ա��
class Employee : public Worker{
public:
    //���캯��
    Employee(int id, string name, int dId); //��ʼ��id�����֣���λ���
    //��ʾ������Ϣ
    virtual void showInfo();
    //��ȡ��λ����
    virtual string getDeptName();
};