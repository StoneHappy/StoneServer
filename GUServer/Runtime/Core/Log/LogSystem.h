#pragma once

namespace GU
{
    class Log
    {
    public:
        static Log* GetInstance()
        {
            static Log instance;
            return &instance;
        }

        void Init(const char* file_name);
        
        void WriteLog(int level, const char* format, ...);
    private:
        char log_name[128];
        char dir_name[128]; //路径名
        Log() = default;

        virtual ~Log() = default;
    };
} // namespace GU
