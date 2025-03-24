#pragma once
#include "Logger.h"
#include <sstream>
namespace tmms
{
    namespace base
    {
        extern Logger * g_logger;
        class LogStream
        {
        public:
            LogStream(Logger* logger, const char* file, int line, LogLevel l, const char *func);
            ~LogStream();

            // 模板实现必须放在头文件中
            template<class T>
            LogStream& operator<<(const T& value)
            {
                stream_<< value;
                return *this;
            }

        private:
            std::ostringstream stream_;
            Logger *logger_{nullptr};
        };
    }
}


 // 修正日志宏定义（添加缺失的__func__参数）
#define LOG_TRACE LogStream(tmms::base::g_logger, __FILE__, __LINE__, tmms::base::kTrace, __func__)
#define LOG_DEBUG LogStream(tmms::base::g_logger, __FILE__, __LINE__, tmms::base::kDebug, __func__)
#define LOG_INFO  LogStream(tmms::base::g_logger, __FILE__, __LINE__, tmms::base::kInfo, __func__)
#define LOG_WARN  LogStream(tmms::base::g_logger, __FILE__, __LINE__, tmms::base::kWarn, __func__)
#define LOG_ERROR LogStream(tmms::base::g_logger, __FILE__, __LINE__, tmms::base::kError, __func__)
