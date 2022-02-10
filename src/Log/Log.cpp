#include "Log/Log.h"
#include <string.h>
#include <iostream>
#include <stdarg.h>
namespace GU
{
    void Log::Init(const char* filename)
    {
        const char* p = strrchr(filename, '/');
        if (p == NULL)
        {
            std::cout << "p is Null" << std::endl;
        }
        else
        {
            std::cout << p << std::endl;
        }
        
    }
} // namespace GU
