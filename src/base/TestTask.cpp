#include "TaskMgr.h"
#include <iostream>
#include <memory>
#include <thread>  // 添加头文件
#include <chrono>  // 添加头文件
using namespace tmms::base;
void TestTask(){
    TaskPtr task1 = std::make_shared<Task>([](const TaskPtr &task)
        {
            std::cout<<"task1 interval:"<<1000<<std::endl;
        },
        1000
    );
    TaskPtr task2 = std::make_shared<Task>([](const TaskPtr &task)
        {
            std::cout<<"task2 interval:"<<500<<std::endl;
            task->Restart();
        },
        500
    );
    TaskPtr task3 = std::make_shared<Task>([](const TaskPtr &task)
        {
            std::cout<<"task3 interval:"<<1500<<std::endl;
            task->Restart();
        },
        1500
    );
    TaskPtr task4 = std::make_shared<Task>([](const TaskPtr &task)
        {
            std::cout<<"task4 interval:"<<100<<std::endl;
            task->Restart();
        },
        100
    );
    
    sTaskMgr->Add(task1);
    sTaskMgr->Add(task2);
    sTaskMgr->Add(task3);
    sTaskMgr->Add(task4);
}
int main(int argc, const char **argc){
    TestTask();
    while(1)
    {
        sTaskMgr->OnWork();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    return 0;

}