#include "TaskMgr.h"
#include "Task.h"
#include "TTime.h"
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

using namespace tmms::base;

void TestTask() {
    try {
        TaskPtr task1 = std::make_shared<Task>([](const TaskPtr &task) {
            std::cout << "task1 interval: " << 1000 << " now: " << TTime::NowMS() << std::endl;
            task->Restart();  // 添加重启逻辑保持任务统一行为
        }, 1000);

        TaskPtr task2 = std::make_shared<Task>([](const TaskPtr &task) {
            std::cout << "task2 interval: " << 500 << " now: " << TTime::NowMS() << std::endl;
            task->Restart();
        }, 500);

        TaskPtr task3 = std::make_shared<Task>([](const TaskPtr &task) {
            std::cout << "task3 interval: " << 1500 << " now: " << TTime::NowMS()<< std::endl;
            task->Restart();
        }, 1500);

        TaskPtr task4 = std::make_shared<Task>([](const TaskPtr &task) {
            std::cout << "task4 interval: " << 100 << " now: " << TTime::NowMS()<< std::endl;
            task->Restart();
        }, 100);

        sTaskMgr->Add(task1);
        sTaskMgr->Add(task2);
        sTaskMgr->Add(task3);
        sTaskMgr->Add(task4);
    } catch (const std::exception &e) {
        std::cerr << "Error in TestTask: " << e.what() << std::endl;
    }
}

int main(int argc, const char **argv) {
    try {
        TestTask();
        while (true) {
            sTaskMgr->OnWork();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    } catch (const std::exception &e) {
        std::cerr << "Error in main: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}