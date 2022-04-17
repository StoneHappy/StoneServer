#include "Core/Base/PublicSingleton.h"
#include <iostream>
#include <Core/Log/LogSystem.h>
int main()
{
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().Init("test", 0);
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().WriteLog(0, "%s", "sdsdd");
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().WriteLog(0, "%s", "asdsadsad");
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().WriteLog(1, "%s", "asdsadsad");
    std::cout << "hello StoneServer" << std::endl;
}