//
// Created by Morning_Maple on 2022.11.16.
//

#include "workerManager.h"


//构造函数
WorkerManager::WorkerManager(){
    //初始化属性
    //1.文件不存在
    ifstream  ifs;
    ifs.open(FILENAME, ios::in);    //读文件
    if(!ifs.is_open()){
            //cout << "文件不存在！" << endl;
        this->m_EmpNum = 0; //初始化总人数
        this->m_EmpArray = NULL;    //初始化数组指针
        this->m_FileIsEmpty = true; //初始化文件是否为空
        ifs.close();
        return;
    }
    //2.文件存在，数据为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
            //cout << "文件为空！" << endl;
        this->m_EmpNum = 0; //初始化总人数
        this->m_EmpArray = NULL;    //初始化数组指针
        this->m_FileIsEmpty = true; //初始化文件是否为空
        ifs.close();
        return;
    }
    //3.文件存在，数据存在
    int num = this->get_EmpNum();
        //cout << "现有人数为：" << num << endl;
    this->m_EmpNum = num;
    //开辟空间
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    //把文件中的数据，存到数组中
    this->init_Emp();
    this->m_FileIsEmpty = false;
}

//选择范围外
void WorkerManager::OutOfRange() {
    cout << "选项不在范围，请重新选择" << endl;
    system("pause");
}

//菜单
void WorkerManager::Show_Menu() {
    cout << "*************************" << endl;
    cout << "*****  欢迎使用本系统 *****" << endl;
    cout << "*****    0.退出系统  *****" << endl;
    cout << "*****    1.增加成员  *****" << endl;
    cout << "*****    2.显示成员  *****" << endl;
    cout << "*****    3.删除成员  *****" << endl;
    cout << "*****    4.修改成员  *****" << endl;
    cout << "*****    5.查找成员  *****" << endl;
    cout << "*****    6.编号排序  *****" << endl;
    cout << "*****    7.清空存储  *****" << endl;
    cout << "*************************" << endl;
    cout << endl;
}

//退出系统
void WorkerManager::ExitSystem(){
    cout << "感谢使用，下次再见" << endl;
    system("pause");
    exit(0);
}

//添加职工
void WorkerManager::Add_Emp(){
    cout << "请输入添加数量：" << endl;
    int addNum = 0;
    cin >> addNum;
    if(addNum > 0){
        //添加
        //计算添加的新的空间大小
        int newSize = this->m_EmpNum + addNum;  //新空间人数 = 原来人数 + 新增人数

        Worker ** newSpace = new Worker*[newSize];  //开辟新空间
        //把原来空间下的数据，拷贝到新空间下
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //批量添加新数据
        for(int i = 0; i < addNum; i++){
            int id; //编号
            string name;    //姓名
            int dSelect;    //部门

            cout << "请输入第" << i+1 << "个新职工的编号：" << endl;
            cin >> id;
            cout << "请输入第" << i+1 << "个新职工的姓名：" << endl;
            cin >> name;
            cout << "请选择该职工的岗位：" << endl;
            cout << "1.职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL; //父类指针
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
            //把创建的职工指针，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;  //m_EmpNum为数组尾
        }
        //释放原有空间
        delete [] this->m_EmpArray;
        //更改新的空间指向
        this->m_EmpArray = newSpace;
        //更新总人数
        this->m_EmpNum = newSize;
        this->save();   //保存数据
        this->m_FileIsEmpty = false;    //跟香港职工人数不为空的标志
        cout << "成功添加" << addNum << "名职工" << endl;
    }
    else{
        cout << "错误，不接受小于零的数！" << endl;
    }
    system("pause");
}

//保存文件
void WorkerManager::save(){
    ofstream  ofs;
    ofs.open(FILENAME, ios::out);   //以输出方式打开文件/写文件

    //把每个人的数据写入文件中
    for(int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_ID << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptID << endl;
    }
    ofs.close();    //关闭文件
}

//统计文件中人数
int WorkerManager::get_EmpNum(){
    ifstream  ifs;
    ifs.open(FILENAME, ios::in);    //打开文件读
    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs >> id && ifs >> name && ifs >> dId){
        num++;  //统计人数
    }
    return num;
}

//初始化员工
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;

    while(ifs >> id && ifs >> name && ifs >> dId){
        Worker * worker = NULL;
        if(dId == 1){   //普通
            worker = new Employee(id, name, dId);
        }
        else if(dId == 2){  //经理
            worker = new Manager(id, name, dId);
        }
        else{  //老板
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();    //关闭文件
}

//显示职工
void WorkerManager::Show_Emp(){
    //判断文件是否为空
    if(this->m_FileIsEmpty){
        cout << "文件不存在或者记录为空" << endl;
    }
    else{
        for(int i = 0; i < m_EmpNum; ++i){
            //利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
}

//删除职工
void WorkerManager::Del_Emp(){
    if(this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else{
        cout << "输入需要删除的职工编号：" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if(index != -1){
            //数据前移
            for(int i = index; i < this->m_EmpNum - 1; i++){
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;   //更新总人数
            this->save();   //数据同步更新到文件中
            cout << "成功" << endl;
        }
        else{
            cout << "找不到目标" << endl;
        }
    }
    system("pause");
}

//判断职工是否存在
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

//修改
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else{
        cout << "输入修改的职工编号：" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if(ret != -1){
            //成功查找
            delete this->m_EmpArray[ret];   //清空原来的堆区数据

            int newID = 0;
            string  newName = "";
            int dSelect = 0;

            cout << "查找到" << id << "号的信息，请输入新的编号：" << endl;
            cin >> newID;

            cout << "请输入新的姓名：" << endl;
            cin >> newName;

            cout << "请输入新的岗位：" << endl;
            cout << "1.职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
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
            //更新数据到数组中
            this->m_EmpArray[ret] = worker;
            cout << "成功" << endl;
            this->save();
        }
        else{
            cout << "失败，没有找到目标" << endl;
        }
    }
    system("pause");
}

//查找
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
    }
    else{
        cout << "输入查找的方式：" << endl;
        cout << "1.按职工编号查找 " << endl;
        cout << "2.按职工姓名查找 " << endl;

        int select = 0;
        cin >> select;

        if(select == 1){
            //按编号查找
            int id;
            cout << "输入需要查找的编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if(ret != -1){
                cout << "成功找到，信息如下" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else{
                cout << "失败，查无此人" << endl;
            }
        }

        else if(select == 2){
            //按姓名查
            string name;
            cout << "输入需要查找的姓名：" << endl;
            cin >> name;
            //判断是否查到的标准
            bool flag = false;    //默认找不到

            for (int i = 0; i < m_EmpNum; i++){
                if(this->m_EmpArray[i]->m_Name == name){
                    cout << "成功，目标编号为" << this->m_EmpArray[i]->m_ID << "的信息如下" << endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();    //调用显示信息的接口
                }
            }
            if(flag == false){
                cout << "失败，查无此人" << endl;
            }
        }
        else{
            cout << "输入有误" << endl;
        }
    }
    system("pause");
}

//排序
void WorkerManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout << "文件不存在或记录为空" << endl;
        system("pause");
    }
    else{
        cout << "选择排序方式：" << endl;
        cout << "1.按编号升序" << endl;
        cout << "2.按编号降序" << endl;

        int select = 0;
        cin >> select;
        for(int i = 0; i < m_EmpNum; i++){
            int minOrMax = i;   //声明最小值 或 最大值下标
            for(int j = i + 1; j < this->m_EmpNum; j++){
                if(select == 1){    //升序
                    if(this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID){
                        minOrMax = j;
                    }
                }
                else{   //输入有误都按降序处理
                    if(this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID){
                        minOrMax = j;
                    }
                }
            }
            //判断开始认定的最小值或最大值是不是计算的最小值或最大值，若不是，交换数据
            if(i != minOrMax){
                Worker * temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "排序成功，结果为：" << endl;
        this->save();   //把排序结果更新到文件中
        this->Show_Emp();
    }
}

//清空文件
void WorkerManager::Clean_File(){
    cout << "清空？" << endl;
    cout << "1.确定" << endl;
    cout << "2.取消" << endl;

    int select = 0;
    cin >> select;
    if(select == 1){
        //清空
        ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
        ofs.close();
        if(this->m_EmpArray != NULL){
            //删除堆区的每个职工对象
            for (int i = 0; i < this->m_EmpNum; i++){
                if (this->m_EmpArray[i] != NULL){
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            //删除堆区数组指针
            delete [] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "成功" << endl;
    }
    system("pause");
}


//析构函数
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
