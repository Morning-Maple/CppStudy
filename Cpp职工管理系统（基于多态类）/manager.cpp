//
// Created by Morning_Maple on 2022.11.17.
//

#include "manager.h"

//���캯��������ʼ��id�����֣���λ���
Manager::Manager(int id, string name, int dId){
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}
//��ʾ������Ϣ
void Manager::showInfo(){
    cout << "ְ����ţ�" << this->m_ID
         << "\tְ��������" << this->m_Name
         << "\tְ����λ��" << this->getDeptName()
         << "\t��λְ�����ϰ�Ļ�������Ա����" << endl;
}
//��ȡ��λ����
string Manager::getDeptName(){
    return string("����");  //ת��Ϊ�ַ�������
}