#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <execinfo.h>
#include <vector>
#include <sstream>
#include <threads.h>
#include <sys/time.h>
#include <cxxabi.h> 
#include "log.h"
//断言宏封装
#define ZYX_ASSERT(x,str) \
         if(!(x)){\
            std::cout<<zyx::BacktraceToString(20,str)<<std::endl;\
            assert(x);\
         }
namespace zyx
{
   pid_t GetThreadId();

   void Backtrace(std::vector<std::string>& bt,int size);
   std::string BacktraceToString(int size,const std::string str);
   static std::string demangle(const char* str);

   //获取当前时间ms
   uint64_t GetCurrentMS();
}
#endif
