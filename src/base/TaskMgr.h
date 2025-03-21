#pragma once
#include "Task.h"
#include "Singleton.h"
#include <unordered_set>
#include <mutex>
namespace tmms
{
    namespace base
    {
        class TaskMgr : public NonCopyable
        {
        public:
            TaskMgr() = default;
            ~TaskMgr() = default;

            void OnWork();
            bool Add(TaskPtr &task); //TaskPtr  -》 std::shared_ptr<Task>;
            bool Del(TaskPtr &task);
        private:
           std::unordered_set<TaskPtr> tasks_;
           std::mutex mutex_;

        };
        
    } // namespace base
    #define sTaskMgr tmms::base::Singleton<tmms::base::TaskMgr>::Instance()
} // namespace tmms