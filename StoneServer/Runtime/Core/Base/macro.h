#pragma once

#include "Core/Log/LogSystem.h"
#define LOG_HELPER(LOG_LEVEL, ...) \
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().WriteLog(LOG_LEVEL, __VA_ARGS__);

#define LOG_DEBUG(...) LOG_HELPER(0, __VA_ARGS__);

#define LOG_INFO(...) LOG_HELPER(1, __VA_ARGS__);

#define LOG_WARN(...) LOG_HELPER(2, __VA_ARGS__);

#define LOG_ERROR(...) LOG_HELPER(3, __VA_ARGS__);
