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
        bool Init(const char* file_name, int close_log, int log_buf_size = 8192, int split_lines = 5000000);
        
        void WriteLog(int level, const char* format, ...);

        void flush();
    private:
        char log_name[128];
        char dir_name[128]; //路径名
        FILE* m_fp;
        int m_split_lines;  //日志最大行数
        int m_log_buf_size; //日志缓冲区大小
        int m_close_log;
        int m_is_initialized = false;

        char* m_buf;
    };
} // namespace GU
