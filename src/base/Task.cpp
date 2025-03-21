#include "Task.h"
#include "TTime.h"
#include <iostream>

using namespace tmms::base;

Task::Task(const TaskCallback &cb, int64_t interval)
:interval_(interval), when_(TTime::NowMS() + interval), cb_(cb)
{

}
Task::Task(const TaskCallback &&cb, int64_t interval)
:interval_(interval), when_(TTime::NowMS() + interval), cb_(std::move(cb))
{

}

void Task::Run()
{
    if(cb_)
    {
        cb_(shared_from_this());
    }

}
void Task::Restart()
{
    when_ = TTime::NowMS() + interval_;
    // 添加调试输出
    std::cout << "Task restarted, next at: " << when_ << std::endl;
}