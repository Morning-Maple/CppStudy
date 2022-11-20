//
// Created by Morning_Maple on 2022.11.16.
//

#include "workerManager.h"


//���캯��
WorkerManager::WorkerManager(){
    //��ʼ������
    //1.�ļ�������
    ifstream  ifs;
    ifs.open(FILENAME, ios::in);    //���ļ�
    if(!ifs.is_open()){
            //cout << "�ļ������ڣ�" << endl;
        this->m_EmpNum = 0; //��ʼ��������
        this->m_EmpArray = NULL;    //��ʼ������ָ��
        this->m_FileIsEmpty = true; //��ʼ���ļ��Ƿ�Ϊ��
        ifs.close();
        return;
    }
    //2.�ļ����ڣ�����Ϊ��
    char ch;
    ifs >> ch;
    if(ifs.eof()){
            //cout << "�ļ�Ϊ�գ�" << endl;
        this->m_EmpNum = 0; //��ʼ��������
        this->m_EmpArray = NULL;    //��ʼ������ָ��
        this->m_FileIsEmpty = true; //��ʼ���ļ��Ƿ�Ϊ��
        ifs.close();
        return;
    }
    //3.�ļ����ڣ����ݴ���
    int num = this->get_EmpNum();
        //cout << "��������Ϊ��" << num << endl;
    this->m_EmpNum = num;
    //���ٿռ�
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    //���ļ��е����ݣ��浽������
    this->init_Emp();
    this->m_FileIsEmpty = false;
}

//ѡ��Χ��
void WorkerManager::OutOfRange() {
    cout << "ѡ��ڷ�Χ��������ѡ��" << endl;
    system("pause");
}

//�˵�
void WorkerManager::Show_Menu() {
    cout << "*************************" << endl;
    cout << "*****  ��ӭʹ�ñ�ϵͳ *****" << endl;
    cout << "*****    0.�˳�ϵͳ  *****" << endl;
    cout << "*****    1.���ӳ�Ա  *****" << endl;
    cout << "*****    2.��ʾ��Ա  *****" << endl;
    cout << "*****    3.ɾ����Ա  *****" << endl;
    cout << "*****    4.�޸ĳ�Ա  *****" << endl;
    cout << "*****    5.���ҳ�Ա  *****" << endl;
    cout << "*****    6.�������  *****" << endl;
    cout << "*****    7.��մ洢  *****" << endl;
    cout << "*************************" << endl;
    cout << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem(){
    cout << "��лʹ�ã��´��ټ�" << endl;
    system("pause");
    exit(0);
}

//���ְ��
void WorkerManager::Add_Emp(){
    cout << "���������������" << endl;
    int addNum = 0;
    cin >> addNum;
    if(addNum > 0){
        //���
        //������ӵ��µĿռ��С
        int newSize = this->m_EmpNum + addNum;  //�¿ռ����� = ԭ������ + ��������

        Worker ** newSpace = new Worker*[newSize];  //�����¿ռ�
        //��ԭ���ռ��µ����ݣ��������¿ռ���
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //�������������
        for(int i = 0; i < addNum; i++){
            int id; //���
            string name;    //����
            int dSelect;    //����

            cout << "�������" << i+1 << "����ְ���ı�ţ�" << endl;
            cin >> id;
            cout << "�������" << i+1 << "����ְ����������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1.ְ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> dSelect;

            Worker * worker = NULL; //����ָ��
            switch(dSelect){
                case 1:
                    worker = new Employee(id, name ,1);
                    break;
                case 2:
                    worker = new Manager(id, name ,2);
                    break;
                case 3:
                    worker = new Boss(id, name ,3);
                    break;
                default:
                    break;
            }
            //�Ѵ�����ְ��ָ�룬���浽������
            newSpace[this->m_EmpNum + i] = worker;  //m_EmpNumΪ����β
        }
        //�ͷ�ԭ�пռ�
        delete [] this->m_EmpArray;
        //�����µĿռ�ָ��
        this->m_EmpArray = newSpace;
        //����������
        this->m_EmpNum = newSize;
        this->save();   //��������
        this->m_FileIsEmpty = false;    //�����ְ��������Ϊ�յı�־
        cout << "�ɹ����" << addNum << "��ְ��" << endl;
    }
    else{
        cout << "���󣬲�����С���������" << endl;
    }
    system("pause");
}

//�����ļ�
void WorkerManager::save(){
    ofstream  ofs;
    ofs.open(FILENAME, ios::out);   //�������ʽ���ļ�/д�ļ�

    //��ÿ���˵�����д���ļ���
    for(int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_ID << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptID << endl;
    }
    ofs.close();    //�ر��ļ�
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum(){
    ifstream  ifs;
    ifs.open(FILENAME, ios::in);    //���ļ���
    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs >> id && ifs >> name && ifs >> dId){
        num++;  //ͳ������
    }
    return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;

    while(ifs >> id && ifs >> name && ifs >> dId){
        Worker * worker = NULL;
        if(dId == 1){   //��ͨ
            worker = new Employee(id, name, dId);
        }
        else if(dId == 2){  //����
            worker = new Manager(id, name, dId);
        }
        else{  //�ϰ�
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();    //�ر��ļ�
}

//��ʾְ��
void WorkerManager::Show_Emp(){
    //�ж��ļ��Ƿ�Ϊ��
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else{
        for(int i = 0; i < m_EmpNum; ++i){
            //���ö�̬���ó���ӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
}

//ɾ��ְ��
void WorkerManager::Del_Emp(){
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else{
        cout << "������Ҫɾ����ְ����ţ�" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if(index != -1){
            //����ǰ��
            for(int i = index; i < this->m_EmpNum - 1; i++){
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;   //����������
            this->save();   //����ͬ�����µ��ļ���
            cout << "�ɹ�" << endl;
        }
        else{
            cout << "�Ҳ���Ŀ��" << endl;
        }
    }
    system("pause");
}

//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id){
    int index = -1;
    for(int i = 0; i < this->m_EmpNum; i++){
        if(this->m_EmpArray[i]->m_ID == id){
            index = i;
            break;
        }
    }
    return index;
}

//�޸�
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else{
        cout << "�����޸ĵ�ְ����ţ�" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if(ret != -1){
            //�ɹ�����
            delete this->m_EmpArray[ret];   //���ԭ���Ķ�������

            int newID = 0;
            string  newName = "";
            int dSelect = 0;

            cout << "���ҵ�" << id << "�ŵ���Ϣ���������µı�ţ�" << endl;
            cin >> newID;

            cout << "�������µ�������" << endl;
            cin >> newName;

            cout << "�������µĸ�λ��" << endl;
            cout << "1.ְ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch(dSelect){
                case 1:
                    worker = new Employee(newID, newName, dSelect);
                    break;
                case 2:
                    worker = new Manager(newID, newName, dSelect);
                    break;
                case 3:
                    worker = new Boss(newID, newName, dSelect);
                    break;
                default:
                    break;
            }
            //�������ݵ�������
            this->m_EmpArray[ret] = worker;
            cout << "�ɹ�" << endl;
            this->save();
        }
        else{
            cout << "ʧ�ܣ�û���ҵ�Ŀ��" << endl;
        }
    }
    system("pause");
}

//����
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else{
        cout << "������ҵķ�ʽ��" << endl;
        cout << "1.��ְ����Ų��� " << endl;
        cout << "2.��ְ���������� " << endl;

        int select = 0;
        cin >> select;

        if(select == 1){
            //����Ų���
            int id;
            cout << "������Ҫ���ҵı�ţ�" << endl;
            cin >> id;

            int ret = IsExist(id);
            if(ret != -1){
                cout << "�ɹ��ҵ�����Ϣ����" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else{
                cout << "ʧ�ܣ����޴���" << endl;
            }
        }

        else if(select == 2){
            //��������
            string name;
            cout << "������Ҫ���ҵ�������" << endl;
            cin >> name;
            //�ж��Ƿ�鵽�ı�׼
            bool flag = false;    //Ĭ���Ҳ���

            for (int i = 0; i < m_EmpNum; i++){
                if(this->m_EmpArray[i]->m_Name == name){
                    cout << "�ɹ���Ŀ����Ϊ" << this->m_EmpArray[i]->m_ID << "����Ϣ����" << endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();    //������ʾ��Ϣ�Ľӿ�
                }
            }
            if(flag == false){
                cout << "ʧ�ܣ����޴���" << endl;
            }
        }
        else{
            cout << "��������" << endl;
        }
    }
    system("pause");
}

//����
void WorkerManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
        system("pause");
    }
    else{
        cout << "ѡ������ʽ��" << endl;
        cout << "1.���������" << endl;
        cout << "2.����Ž���" << endl;

        int select = 0;
        cin >> select;
        for(int i = 0; i < m_EmpNum; i++){
            int minOrMax = i;   //������Сֵ �� ���ֵ�±�
            for(int j = i + 1; j < this->m_EmpNum; j++){
                if(select == 1){    //����
                    if(this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID){
                        minOrMax = j;
                    }
                }
                else{   //�������󶼰�������
                    if(this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID){
                        minOrMax = j;
                    }
                }
            }
            //�жϿ�ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ�������ǣ���������
            if(i != minOrMax){
                Worker * temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "����ɹ������Ϊ��" << endl;
        this->save();   //�����������µ��ļ���
        this->Show_Emp();
    }
}

//����ļ�
void WorkerManager::Clean_File(){
    cout << "��գ�" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.ȡ��" << endl;

    int select = 0;
    cin >> select;
    if(select == 1){
        //���
        ofstream ofs(FILENAME, ios::trunc); //ɾ���ļ������´���
        ofs.close();
        if(this->m_EmpArray != NULL){
            //ɾ��������ÿ��ְ������
            for (int i = 0; i < this->m_EmpNum; i++){
                if (this->m_EmpArray[i] != NULL){
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            //ɾ����������ָ��
            delete [] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "�ɹ�" << endl;
    }
    system("pause");
}


//��������
WorkerManager::~WorkerManager(){
    if(this->m_EmpArray != NULL){
        for(int i = 0; i < this->m_EmpNum; i++){
            if(this->m_EmpArray[i] != NULL){
                delete this->m_EmpArray[i];
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
