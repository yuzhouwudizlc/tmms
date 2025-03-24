#include "LogStream.h"
#include <string>
#include "TTime.h"
#include <unistd.h>
#include <sys/syscall.h>
#include <cstring>
using namespace tmms::base;


Logger* tmms::base::g_logger = nullptr;
static thread_local pid_t thread_id = 0;
const char *log_string[]{

};

LogStream::LogStream(Logger* logger, const char* file, int line, LogLevel l, const char *func)
:logger_(logger)
{
    if(l < tmms::base::g_logger->GetLogLevel())
        return;
    // 初始化时清空流缓冲区
    stream_.str("");
    stream_.clear();

    // 统一格式：[时间][线程ID][文件名:行号][函数名]
    stream_ << "[" << TTime::ISOTime() << "]";  // 时间戳

    // 获取线程ID
    if(thread_id == 0){
        thread_id = static_cast<pid_t>(syscall(SYS_gettid));
    }
    stream_ << "[TID:" << thread_id << "]";     // 线程信息

    // 文件名处理
    const char * file_name = strrchr(file,'/');
    file_name = file_name ? file_name + 1 : file;
    stream_ << "[" << file_name << ":" << line << "]"; // 源码位置

    // 函数名处理
    if(func){
        stream_ << "[FN:" << func << "]";
    }
    // 日志内容前缀
    stream_ << " ";
}

LogStream::~LogStream()
{
    stream_ << "\n";  // 添加换行
    logger_->Write(stream_.str());
}
