//
// Created by Morning_Maple on 2022.11.17.
//

#include "boss.h"

//���캯��������ʼ��id�����֣���λ���
Boss::Boss(int id, string name, int dId){
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}
//��ʾ������Ϣ
void Boss::showInfo(){
    cout << "ְ����ţ�" << this->m_ID
         << "\tְ��������" << this->m_Name
         << "\tְ����λ��" << this->getDeptName()
         << "\t��λְ������һ������㣡" << endl;
}
//��ȡ��λ����
string Boss::getDeptName(){
    return string("�ϰ�");  //ת��Ϊ�ַ�������
}
