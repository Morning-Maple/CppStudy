#include <iostream>
#include <string>
using namespace std;

#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main(){

//    //跑测试
//    Worker * worker = NULL;
//    worker = new Employee(1, "张三", 1);
//    worker->showInfo();
//    delete worker;
//    worker = new Manager(2, "张三", 2);
//    worker->showInfo();
//    delete worker;
//    worker = new Boss(3, "张三", 3);
//    worker->showInfo();
//    delete worker;

    //实例化管理者对象
    WorkerManager wm;
    int choice = 0;
    while (true){
        wm.Show_Menu();
        cout << "输入您的选择：" << endl;
        cin >> choice;
        switch(choice){
            case 0: //退出
                wm.ExitSystem();
                break;
            case 1: //增加
                wm.Add_Emp();
                break;
            case 2: //显示
                wm.Show_Emp();
                break;
            case 3: //删除
                wm.Del_Emp();
                break;
            case 4: //修改
                wm.Mod_Emp();
                break;
            case 5: //查询
                wm.Find_Emp();
                break;
            case 6: //排序
                wm.Sort_Emp();
                break;
            case 7: //清空
                wm.Clean_File();
                break;
            default:
                wm.OutOfRange();
                break;
        }
    }
    system("pause");
    return 0;
}
