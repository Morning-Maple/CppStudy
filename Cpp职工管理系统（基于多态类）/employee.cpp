//
// Created by Morning_Maple on 2022.11.16.
//

#include "employee.h"

//���캯��������ʼ��id�����֣���λ���
Employee::Employee(int id, string name, int dId){
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = dId;
}
//��ʾ������Ϣ
void Employee::showInfo(){
    cout << "ְ����ţ�" << this->m_ID
        << "\tְ��������" << this->m_Name
        << "\tְ����λ��" << this->getDeptName()
        << "\t��λְ�𣺺úøɻ��׼���㣡" << endl;
}
//��ȡ��λ����
string Employee::getDeptName(){
    return string("Ա��");  //ת��Ϊ�ַ�������
}