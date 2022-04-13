#include "Core/Log/LogSystem.h"
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdarg.h>
namespace GU
{
    void Log::Init(const char* filename)
    {
        time_t t = time(NULL);
        struct tm* sys_tm = localtime(&t);
        struct tm  my_tm = *sys_tm;
        const char* p = strrchr(filename, '/');
        char log_full_name[256] = {0};
        if (p == NULL)
        {
            snprintf(log_full_name, 255, "%d_%02d_%02d_%s", my_tm.tm_year+1900, my_tm.tm_mon + 1, my_tm.tm_mday, filename);
        }
        else
        {
            strcpy(log_name, p+1);
            strncpy(dir_name, filename, p-filename+1);
            snprintf(log_full_name, 255, "%s%d_%02d_%02d_%s", dir_name, my_tm.tm_year+1900, my_tm.tm_mon + 1, my_tm.tm_mday, log_name);
        }
        printf("%s\n", log_full_name);
    }
} // namespace GU
