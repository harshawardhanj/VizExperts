#ifndef UFERRARIENGINE_H
#define UFERRARIENGINE_H
#include <FerrariEngine.h>
#include <iostream>

class UFerrariEngine : public FerrariEngine
{
public:
    UFerrariEngine();
    size_t getPower();
    void LogEngineTemperature();
};

#endif // UFERRARIENGINE_H
