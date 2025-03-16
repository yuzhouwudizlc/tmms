#include "Singleton.h"
#include "NonCopyable.h"
#include <iostream>
using namespace tmms::base;
class A:public NonCopyable
{
public:
    A() = default;
    ~A() = default;
    void Print()
    {
        std::cout<<"This is A"<<std::endl;
    }
};

#define sA tmms::base::Singleton<A>::Instance()
int main(int argc,const char ** argv)
{
    sA->Print();
    return 0;
}