#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Person{  //定义一个结构体（细分）
    string m_Name;
    int sex;    //1男2女
    int m_Age;
    string m_Phone;
    string m_Address;
};

struct Addressbooks{    //定义一个结构体（整体），包含一个int（总数）和一个结构体
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(Addressbooks * abs){ //添加人
    if(abs->m_Size == MAX){
        cout << "存储已满，不能添加" << endl;
        return;
    }
    else{

        string name;
        cout << "输入姓名：" << endl;
        cin >> name;
        abs -> personArray[abs->m_Size].m_Name = name;

        cout << "输入性别：" << endl;
        cout << "1 —— 男" << endl;
        cout << "2 —— 女" << endl;
        int sex = 0;
        while(true){
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs ->personArray[abs->m_Size].sex = sex;
                break;
            }
            else{
                cout << "错误，重新输入：" << endl;
            }
        }

        cout << "输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs ->personArray[abs->m_Size].m_Age = age;

        cout << "输入电话：" << endl;
        string phone;
        cin >> phone;
        abs ->personArray[abs->m_Size].m_Phone = phone;

        cout << "输入地址：" << endl;
        string address;
        cin >> address;
        abs ->personArray[abs->m_Size].m_Address = address;

        abs->m_Size++;
        cout << "添加成功" << endl;
        system("pause");
    }
}

void showPerson(Addressbooks * abs){    //展示全部人信息
    if(abs->m_Size == 0){
        cout << "当前记录为空" << endl;
    }
    else{
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "姓名:" << abs->personArray[i].m_Name << "\t"
            << "性别:" << (abs->personArray[i].sex == 1 ? "男":"女") << "\t"
            << "年龄:" << abs->personArray[i].m_Age << "\t"
            << "电话:" << abs->personArray[i].m_Phone << "\t"
            << "地址:" << abs->personArray[i].m_Address << endl;
        }
    }
    system("pause");
}

int isExist(Addressbooks * abs , string name){  //查找有无此人，有则返回i，否则返回-1
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}

void deletPerson(Addressbooks * abs){   //采用后面数据轮流往前移的方式（即覆盖）来实现删除
    cout << "输入您要删除的人的姓名：" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1){
        for (int i = ret; i < abs->m_Size; i++) {
            abs->personArray[i] = abs->personArray[i+1];    //数据前移
        }
        abs->m_Size--;  //更新总人数
        cout <<"成功" << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    system("pause");
}

void findPersong(Addressbooks * abs){   //查找人，只显示目标人
    cout << "输入您需要查找的人：" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){

        cout << "姓名:" << abs->personArray[ret].m_Name << "\t"
             << "性别:" << (abs->personArray[ret].sex == 1 ? "男":"女") << "\t"
             << "年龄:" << abs->personArray[ret].m_Age << "\t"
             << "电话:" << abs->personArray[ret].m_Phone << "\t"
             << "地址:" << abs->personArray[ret].m_Address << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    system("pause");
}

void modifyPerson(Addressbooks * abs){  //修改目标信息
    cout << "输入您需要查找的人：" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1){
        cout <<"找到目标，开始进行修改..." <<endl;
        string name;
        cout << "输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        cout << "输入性别：" << endl;
        cout <<"1————男" << endl;
        cout <<"2————女" << endl;
        int sex = 0;
        while(true){
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personArray[ret].sex= sex;
                break;
            }
            cout << "错误，重新输入：" << endl;
        }
        int age = 0;
        cout << "输入年龄：" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;
        string phone;
        cout << "输入电话：" << endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        string address;
        cout << "输入地址：" << endl;
        cin >> address;
        abs->personArray[ret].m_Address = address;
        cout << "完毕！" << endl;

    }
    else{
        cout << "查无此人" << endl;
    }
    system("pause");
}

void showMenu(){
    cout << "************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****    0.退出     *****" << endl;
    cout << "************************" << endl;
}

void cleanPerson(Addressbooks * abs){   //结构体数据访问不到就行，后续数据会覆盖掉原本已有的数据
    abs->m_Size = 0;
    cout << "已清空" << endl;
    system("pause");
}

int main(){
    struct Addressbooks abs;
    abs.m_Size = 0;
    int select = 0;
    while (true){
        showMenu();
        cout << "请输入您需要的功能：" << endl;
        cin >> select;
        switch(select){
            case 1: //添加联系人
                addPerson(&abs);
                break;
            case 2: //显示联系人
                showPerson(&abs);
                break;
            case 3: //删除联系人
                deletPerson(&abs);
                break;
            case 4: //查找联系人
                findPersong(&abs);
                break;
            case 5: //修改联系人
                modifyPerson(&abs);
                break;
            case 6: //清空联系人
                cleanPerson(&abs);
                break;
            case 0: //退出
                cout << "您已退出，感谢使用" << endl;
                system("pause");
                return 0;
            default:
                break;
        }
    }
    system("pause");
    return 0;
}
