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
        Log() = default;

        virtual ~Log() = default;
    };
} // namespace GU
