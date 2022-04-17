#include "Core/Log/LogSystem.h"
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdarg.h>
namespace Stone
{
    bool LogSystem::Init(const char* filename, int close_log, int log_buf_size, int split_lines)
    {
        // 初始化参数设置
        m_split_lines = split_lines;
        m_log_buf_size = log_buf_size;
        m_close_log = close_log;
        m_is_initialized = true;
        m_buf = new char[m_log_buf_size];

        time_t t = time(NULL);
        tm* systemtm = localtime(&t);
        tm  nowtime = *systemtm;

        const char* p = strchr(filename, '/');

        char log_full_name[256] = {0};

        if (p == NULL) {
            snprintf(log_full_name, 255, "%d_%02d_%02d_%s", nowtime.tm_year + 1900, nowtime.tm_mon + 1, nowtime.tm_mday, filename);
        }
        else {
            strcpy(log_name, p+1);
            strncpy(dir_name, filename, p - filename + 1);
            snprintf(log_full_name, 255, "%s%d_%02d_%02d_%s", dir_name, nowtime.tm_year + 1900, nowtime.tm_mon + 1, nowtime.tm_mday, log_name);
        }

        m_fp = std::fopen(log_full_name, "a");

        if (m_fp == NULL) {
            m_is_initialized = false;
            return false;
        }

        return true;
    }

    void LogSystem::WriteLog(int level, const char* format, ...)
    {

        struct timeval now = {0, 0};
        gettimeofday(&now, NULL);
        time_t t = now.tv_sec;
        struct tm *sys_tm = localtime(&t);
        struct tm my_tm = *sys_tm;

        // 如果未初始化就不操作
        // if (!m_is_initialized) {
        //     return;
        // }
        char s[16] = {0};
        switch (level) {
            case 0:
                strcpy(s, "[debug]");
                break;
            case 1:
                strcpy(s, "[info]");
                break;
            case 2:
                strcpy(s, "[warn]");
                break;
            case 3:
                strcpy(s, "[erro]");
                break;
            default:
                strcpy(s, "[info]");
                break;
        }
        va_list args;

        va_start(args, format);
        //写入的具体时间内容格式
        int n = snprintf(m_buf, 48, "%d-%02d-%02d %02d:%02d:%02d.%06ld %s ",
                     my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday,
                     my_tm.tm_hour, my_tm.tm_min, my_tm.tm_sec, now.tv_usec, s);
        int m = vsnprintf(m_buf, n, format, args);

        m_buf[n + m] = '\n';
        m_buf[n + m + 1] = '\0'; 
        va_end(args);
        std::string log_str;
        log_str = m_buf;

        fputs(log_str.c_str(), m_fp);
        // fputs(m_buf, m_fp);

        printf("%s", m_buf);
    }

    void LogSystem::flush()
    {
        fflush(m_fp);
    }


} // namespace GU
