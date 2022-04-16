#pragma once
#include "Core/Base/PublicSingleton.h"
#include <stdarg.h>
#include <string.h>
#include <iostream>
namespace Stone
{
    class LogSystem : public PublicSingleton<LogSystem>
    {
    public:
        bool Init(const char* file_name);
        
        void WriteLog(int level, const char* format, ...);
    private:
        char log_name[128];
        char dir_name[128]; //路径名
        FILE* m_fp;
    };
} // namespace GU
