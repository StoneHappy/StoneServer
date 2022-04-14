#include "Core/Base/PublicSingleton.h"
#include <iostream>
#include <Core/Log/LogSystem.h>
int main()
{
    GU::PublicSingleton<GU::LogSystem>::getInstance().Init("test");
    std::cout << "hello GU Server" << std::endl;
}