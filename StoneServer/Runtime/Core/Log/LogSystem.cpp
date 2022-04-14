#include "Core/Log/LogSystem.h"
#include <cstdio>
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdarg.h>
namespace Stone
{
    void LogSystem::Init(const char* filename)
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
        printf("%s\n", log_full_name);
    }
} // namespace GU
