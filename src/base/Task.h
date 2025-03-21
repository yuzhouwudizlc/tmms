#pragma once
#include <functional>
#include <cstdint>
#include <memory>
namespace tmms
{
    namespace base{
        class Task;
        using TaskPtr = std::shared_ptr<Task>;
        using TaskCallback = std::function<void(const TaskPtr &)>;
        class Task :public std::enable_shared_from_this<Task>
        {
        public:
            Task(const TaskCallback &cb, int64_t interval);
            Task(const TaskCallback &&cb, int64_t interval);
            int64_t When() const{
                return when_;
            }
            void Run();
            void Restart();

        private:
            int64_t interval_{0};
            int64_t when_{0};
            TaskCallback cb_;
        };



    }
   
} // namespace tmms