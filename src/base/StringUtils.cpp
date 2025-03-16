#include "StringUtils.h"
#include <vector>
using namespace tmms::base;
bool StringUtils::StartWith(const std::string &str,const std::string &prefix){
    if(str.size()<prefix.size()){
        return false;
    }
    return str.substr(0,prefix.size())==prefix;
}
bool StringUtils::EndWith(const std::string &str,const std::string &suffix){
    if(str.size()<suffix.size()){
        return false;
    }
    return str.substr(str.size()-suffix.size(),suffix.size())==suffix;
}
std::string StringUtils::FilePath(const std::string &path){
    auto pos = path.find_last_of('/');
    if(pos==std::string::npos){
        return "";
    }
    return path.substr(0,pos);
}
std::string StringUtils::FileNameExt(const std::string &path){
    auto pos = path.find_last_of('/');
    if(pos==std::string::npos){
        return path;
    }
    return path.substr(pos+1);
}
std::string StringUtils::FileName(const std::string &path){
    auto pos = path.find_last_of('/');
    if(pos==std::string::npos){
        return path;
    }
    auto pos2 = path.find_last_of('.');
    if(pos2==std::string::npos){
        return path.substr(pos+1);
    }
    return path.substr(pos+1,pos2-pos-1);
}
std::string StringUtils::Extension(const std::string &path){
    auto pos = path.find_last_of('.');
    if(pos==std::string::npos){
        return "";
    }
    return path.substr(pos+1);
}
std::vector<std::string> StringUtils::SplitString(const std::string &str,const std::string &delim){
    std::vector<std::string> ret;
    size_t last = 0;
    size_t index = str.find_first_of(delim,last);
    while(index!=std::string::npos){
        ret.push_back(str.substr(last,index-last));
        last = index+1;
        index = str.find_first_of(delim,last);
    }
    if(index-last>0){
        ret.push_back(str.substr(last,index-last));
    }
    return ret;
}