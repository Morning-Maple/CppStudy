#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Person{  //����һ���ṹ�壨ϸ�֣�
    string m_Name;
    int sex;    //1��2Ů
    int m_Age;
    string m_Phone;
    string m_Address;
};

struct Addressbooks{    //����һ���ṹ�壨���壩������һ��int����������һ���ṹ��
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(Addressbooks * abs){ //�����
    if(abs->m_Size == MAX){
        cout << "�洢�������������" << endl;
        return;
    }
    else{

        string name;
        cout << "����������" << endl;
        cin >> name;
        abs -> personArray[abs->m_Size].m_Name = name;

        cout << "�����Ա�" << endl;
        cout << "1 ���� ��" << endl;
        cout << "2 ���� Ů" << endl;
        int sex = 0;
        while(true){
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs ->personArray[abs->m_Size].sex = sex;
                break;
            }
            else{
                cout << "�����������룺" << endl;
            }
        }

        cout << "�������䣺" << endl;
        int age = 0;
        cin >> age;
        abs ->personArray[abs->m_Size].m_Age = age;

        cout << "����绰��" << endl;
        string phone;
        cin >> phone;
        abs ->personArray[abs->m_Size].m_Phone = phone;

        cout << "�����ַ��" << endl;
        string address;
        cin >> address;
        abs ->personArray[abs->m_Size].m_Address = address;

        abs->m_Size++;
        cout << "��ӳɹ�" << endl;
        system("pause");
    }
}

void showPerson(Addressbooks * abs){    //չʾȫ������Ϣ
    if(abs->m_Size == 0){
        cout << "��ǰ��¼Ϊ��" << endl;
    }
    else{
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "����:" << abs->personArray[i].m_Name << "\t"
            << "�Ա�:" << (abs->personArray[i].sex == 1 ? "��":"Ů") << "\t"
            << "����:" << abs->personArray[i].m_Age << "\t"
            << "�绰:" << abs->personArray[i].m_Phone << "\t"
            << "��ַ:" << abs->personArray[i].m_Address << endl;
        }
    }
    system("pause");
}

int isExist(Addressbooks * abs , string name){  //�������޴��ˣ����򷵻�i�����򷵻�-1
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}

void deletPerson(Addressbooks * abs){   //���ú�������������ǰ�Ƶķ�ʽ�������ǣ���ʵ��ɾ��
    cout << "������Ҫɾ�����˵�������" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1){
        for (int i = ret; i < abs->m_Size; i++) {
            abs->personArray[i] = abs->personArray[i+1];    //����ǰ��
        }
        abs->m_Size--;  //����������
        cout <<"�ɹ�" << endl;
    }
    else{
        cout << "���޴���" << endl;
    }
    system("pause");
}

void findPersong(Addressbooks * abs){   //�����ˣ�ֻ��ʾĿ����
    cout << "��������Ҫ���ҵ��ˣ�" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){

        cout << "����:" << abs->personArray[ret].m_Name << "\t"
             << "�Ա�:" << (abs->personArray[ret].sex == 1 ? "��":"Ů") << "\t"
             << "����:" << abs->personArray[ret].m_Age << "\t"
             << "�绰:" << abs->personArray[ret].m_Phone << "\t"
             << "��ַ:" << abs->personArray[ret].m_Address << endl;
    }
    else{
        cout << "���޴���" << endl;
    }
    system("pause");
}

void modifyPerson(Addressbooks * abs){  //�޸�Ŀ����Ϣ
    cout << "��������Ҫ���ҵ��ˣ�" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1){
        cout <<"�ҵ�Ŀ�꣬��ʼ�����޸�..." <<endl;
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        cout << "�����Ա�" << endl;
        cout <<"1����������" << endl;
        cout <<"2��������Ů" << endl;
        int sex = 0;
        while(true){
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personArray[ret].sex= sex;
                break;
            }
            cout << "�����������룺" << endl;
        }
        int age = 0;
        cout << "�������䣺" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;
        string phone;
        cout << "����绰��" << endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        string address;
        cout << "�����ַ��" << endl;
        cin >> address;
        abs->personArray[ret].m_Address = address;
        cout << "��ϣ�" << endl;

    }
    else{
        cout << "���޴���" << endl;
    }
    system("pause");
}

void showMenu(){
    cout << "************************" << endl;
    cout << "*****  1.�����ϵ��  *****" << endl;
    cout << "*****  2.��ʾ��ϵ��  *****" << endl;
    cout << "*****  3.ɾ����ϵ��  *****" << endl;
    cout << "*****  4.������ϵ��  *****" << endl;
    cout << "*****  5.�޸���ϵ��  *****" << endl;
    cout << "*****  6.�����ϵ��  *****" << endl;
    cout << "*****    0.�˳�     *****" << endl;
    cout << "************************" << endl;
}

void cleanPerson(Addressbooks * abs){   //�ṹ�����ݷ��ʲ������У��������ݻḲ�ǵ�ԭ�����е�����
    abs->m_Size = 0;
    cout << "�����" << endl;
    system("pause");
}

int main(){
    struct Addressbooks abs;
    abs.m_Size = 0;
    int select = 0;
    while (true){
        showMenu();
        cout << "����������Ҫ�Ĺ��ܣ�" << endl;
        cin >> select;
        switch(select){
            case 1: //�����ϵ��
                addPerson(&abs);
                break;
            case 2: //��ʾ��ϵ��
                showPerson(&abs);
                break;
            case 3: //ɾ����ϵ��
                deletPerson(&abs);
                break;
            case 4: //������ϵ��
                findPersong(&abs);
                break;
            case 5: //�޸���ϵ��
                modifyPerson(&abs);
                break;
            case 6: //�����ϵ��
                cleanPerson(&abs);
                break;
            case 0: //�˳�
                cout << "�����˳�����лʹ��" << endl;
                system("pause");
                return 0;
            default:
                break;
        }
    }
    system("pause");
    return 0;
}
