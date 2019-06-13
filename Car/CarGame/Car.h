#ifndef CAR_H
#define CAR_H

#include <string>
#include <Engine.h>
#include <memory>
#include <UFerrariEngine.h>

class Car
{
public:
    Car(const std::string &name);
    ~Car();

    void SetEngine(std::unique_ptr<UFerrariEngine> &engine);

    void Simulate();

private:
    std::unique_ptr<UFerrariEngine> _engine;
    std::string _carName;
};

#endif // CAR_H
