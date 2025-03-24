#include "LogStream.h"
#include "Logger.h"

using namespace tmms::base;

void TestLog()
{
    LOG_TRACE << "test trace!!!";
    LOG_DEBUG << "test debug!!!";
    LOG_INFO  << "test info!!!";
    LOG_WARN  << "test warn!!!"; // 修正宏名大小写
    LOG_ERROR << "test error!!!";
}
int main (int argc,const char **argv){
    tmms::base::g_logger = new Logger();
    tmms::base::g_logger->SetLogLevel(kTrace);
    //tmms::base::g_logger->SetLogLevel(kWarn);
    TestLog();
    return 0;
}
