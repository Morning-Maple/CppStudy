//
// Created by Morning_Maple on 2022.11.16.
//
//#pragma once������ע�ͺ󣬵����������н��
//#ifndef CPPP2_WORKERMANAGER_H
//#define CPPP2_WORKERMANAGER_H
//
//#endif //CPPP2_WORKERMANAGER_H

#pragma once
#include <iostream>
using namespace std;
#include <string>

//�ܱ�
//ְ�������࣬����ʵ�֣�����Ҫ���Ӧ��Դ�ļ�
class Worker{
public:
    //��ʾ������Ϣ
    virtual void showInfo() = 0;
    //��ȡ��λ����
    virtual string getDeptName() = 0;
    int m_ID;   //��λ���
    string m_Name;  //����
    int m_DeptID;   //���ű��
};