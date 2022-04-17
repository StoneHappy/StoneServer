#include "Core/Base/PublicSingleton.h"
#include <iostream>
#include <Core/Log/LogSystem.h>
#include "Core/Base/macro.h"
int main()
{
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().Init("test", 0);
    LOG_DEBUG("%s", "test");
    LOG_INFO("%s", "help");
    std::cout << "hello StoneServer" << std::endl;
}