#include <iostream>
#include "GuServer.h"
#include "Log/Log.h"
int main()
{
    GU::GuServer guserver;
    guserver.init();
    GU::Log::GetInstance()->Init("./server/ServerLog");
    std::cout << "hello GUServer" << std::endl;
}