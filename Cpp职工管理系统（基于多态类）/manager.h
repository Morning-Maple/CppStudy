//
// Created by Morning_Maple on 2022.11.17.
//
//#pragma once������ע�ͺ󣬵����������н��
//#ifndef CPPP2_MANAGER_H
//#define CPPP2_MANAGER_H
//
//#endif //CPPP2_MANAGER_H

#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//�ӱ�2
//����
class Manager : public Worker{
public:
    //���캯��
    Manager(int id, string name, int dId); //��ʼ��id�����֣���λ���
    //��ʾ������Ϣ
    virtual void showInfo();
    //��ȡ��λ����
    virtual string getDeptName();
};