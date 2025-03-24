#pragma once
#include <iostream>
#include "NonCopyable.h"
namespace tmms
{
    namespace base
    {
        enum LogLevel
        {
            kTrace,
            kDebug,
            kInfo,
            kWarn,
            kError,
            kMaxNumOfLogLevel,
        };

        class Logger:public NonCopyable
        {
        public:
            Logger() = default;
            ~Logger() = default;

            void SetLogLevel(const LogLevel &level);
            LogLevel GetLogLevel() const;
            void Write( const std::string &msg);
        private:
            LogLevel level_{kDebug};
        };
    }
}
