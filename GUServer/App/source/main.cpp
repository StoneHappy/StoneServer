#include "Core/Base/PublicSingleton.h"
#include <iostream>
#include <Core/Log/LogSystem.h>
int main()
{
    Stone::PublicSingleton<Stone::LogSystem>::getInstance().Init("test/test");
    std::cout << "hello StoneServer" << std::endl;
}