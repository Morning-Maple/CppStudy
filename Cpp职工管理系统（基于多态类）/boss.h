//
// Created by Morning_Maple on 2022.11.17.
//
//#pragma once������ע�ͺ󣬵����������н��
//#ifndef CPPP2_BOSS_H
//#define CPPP2_BOSS_H
//
//#endif //CPPP2_BOSS_H

#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//�ӱ�3
//�ϰ�
class Boss : public Worker{
public:
    //���캯��
    Boss(int id, string name, int dId); //��ʼ��id�����֣���λ���
    //��ʾ������Ϣ
    virtual void showInfo();
    //��ȡ��λ����
    virtual string getDeptName();
};