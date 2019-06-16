#include "UFerrariEngine.h"
#include <iostream>
#include "Logger.h"

UFerrariEngine::UFerrariEngine()
{

}
size_t UFerrariEngine::getPower()
{
     return _power;
}




void UFerrariEngine::LogEngineTemperature()
{
    CLogger::GetLogger()->Log("");
       LOGGER->Log(" %Lf degree ", getEngineTemprature());
    std::cout<<" "<< getEngineTemprature()<<" degree \n";
}
