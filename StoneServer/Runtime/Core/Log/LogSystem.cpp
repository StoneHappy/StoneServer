#include "Core/Log/LogSystem.h"
#include <cstring>
#include <time.h>
#include <stdio.h>
namespace Stone
{
    bool LogSystem::Init(const char* filename)
    {
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

        auto m_fp = std::fopen(log_full_name, "a");

        if (m_fp == NULL) {
            return false;
        }

        return true;
    }

    void WriteLog(int level, const char* format, ...)
    {

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
    }

} // namespace GU
