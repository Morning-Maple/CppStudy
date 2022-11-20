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

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"  //�궨��һ���ļ���

class WorkerManager{    //����������
public:
    WorkerManager();    //���캯��

    void OutOfRange();  //ѡ��Χ��

    void Show_Menu();  //�˵�

    void ExitSystem();  //�˳�ϵͳ

    int m_EmpNum;   //ְ������

    Worker ** m_EmpArray; //ְ������ָ��

    void Add_Emp(); //����Ա��

    void save();    //�����ļ�

    bool m_FileIsEmpty; //�ж��ļ��Ƿ�Ϊ�յı�־

    int get_EmpNum(); //ͳ���ļ��е�����

    void init_Emp();    //��ʼ��Ա��

    void Show_Emp();    //��ʾְ��

    void Del_Emp();     //ɾ��ְ��

    int IsExist(int id);    //�ж��Ƿ����ָ��ְ��

    void Mod_Emp();         //�޸�ְ��

    void Find_Emp();    //����ְ��

    void Sort_Emp();    //����

    void Clean_File();  //����ļ�

    ~WorkerManager();   //��������
};