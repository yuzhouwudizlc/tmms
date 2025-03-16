#pragma once
#include <string>
#include <vector>
namespace tmms
{
    namespace base
    {
        class StringUtils
        {
        public:
            static bool StartWith(const std::string &str,const std::string &prefix);//判断str是否以prefix开头
            static bool EndWith(const std::string &str,const std::string &suffix);//判断str是否以suffix结尾
            static std::string FilePath(const std::string &path);//获取文件路径
            static std::string FileNameExt(const std::string &path);//获取文件名+扩展名
            static std::string FileName(const std::string &path);//获取文件名
            static std::string Extension(const std::string &path);//获取文件扩展名
            static std::vector<std::string> SplitString(const std::string &str,const std::string &delim);//分割字符串
        };
    }
}