#pragma once
#include "NonCopyable.h"
#include <pthread.h>
namespace tmms
{
    namespace base
    {
        template<typename T>
        class Singleton : public NonCopyable
        {
        public:
            Singleton() = delete;
            ~Singleton() = delete;

            static T*& Instance()
            {
                //pthread_once(&ponce_, &Singleton::init);：
                // pthread_once 是 POSIX 线程库中的一个函数，用于确保某个函数（这里是 Singleton::init）
                // 在程序运行期间只被调用一次
                pthread_once(&ponce_, &Singleton::init);
                return value_;
            }
        private:
            static void init(){
                if(!value_){
                    value_ = new T();
                }
            }
            static pthread_once_t ponce_;
            static T* value_;  // 声明静态成员变量
        };
        template<typename T>
        pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;
        
        template<typename T>
        T *Singleton<T>::value_ = nullptr;
    }
}