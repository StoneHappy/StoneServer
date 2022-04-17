#include "Core/Base/PublicSingleton.h"
#include <iostream>
#include <Core/Log/LogSystem.h>
int main()
{
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().Init("test", 0);
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().WriteLog(0, "%s", "sdsdd");
    std::cout << "hello StoneServer" << std::endl;
}