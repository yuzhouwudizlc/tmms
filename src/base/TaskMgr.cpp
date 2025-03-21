#include "TaskMgr.h"
#include "TTime.h"
using namespace tmms::base;
void TaskMgr::OnWork(){
    std::lock_guard<std::mutex> lock(mutex_);
    int64_t now = TTime::NowMS();
    for(auto iter = tasks_.begin(); iter != tasks_.end();)
    {
        if((*iter)->When() < now)
        {
           (*iter)->Run();
           if((*iter)->When() < now)
           {
             iter = tasks_.erase(iter);
             continue;
           }
        }
        ++iter;
    }

}
bool TaskMgr::Add(TaskPtr &task)
{
    std::lock_guard<std::mutex> lock(mutex_); //超出作用域自动释放
    auto iteration = tasks_.find(task);
    if(iteration != tasks_.end())
    {
        return false;
    }
    tasks_.emplace(task);
    return true;
}
bool TaskMgr::Del(TaskPtr &task)
{
    std::lock_guard<std::mutex> lock(mutex_);
    tasks_.erase(task);
    return true;
}
