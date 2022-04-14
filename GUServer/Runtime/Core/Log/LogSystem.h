#pragma once
#include "Core/Base/PublicSingleton.h"

namespace GU
{
    class LogSystem : public PublicSingleton<LogSystem>
    {
    public:
        void Init(const char* file_name);
        
        void WriteLog(int level, const char* format, ...) {}
    private:
        char log_name[128];
        char dir_name[128]; //路径名
    };
} // namespace GU
