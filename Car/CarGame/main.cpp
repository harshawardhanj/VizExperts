#include <iostream>
#include <Car.h>
#include <Engine.h>
#include <FerrariEngine.h>
#include <memory>
#include <thread>
#include <Logger.h>
#include <UFerrariEngine.h>

 using namespace std;


/**
 * @brief During the development of "FerrariEngine" plugin, Engineer forgot include Car's Power along
 *        with timestamp in its Temperature Logging functionality.
 * @return
 */
int main()
{
    std::unique_ptr<Car> car(new Car("Ferrari"));

    std::unique_ptr<UFerrariEngine> updatedEngine(new UFerrariEngine());   //incomplete Engine,

    car->SetEngine(updatedEngine);

    thread t(&Car::Simulate, car.get());

    t.join();

    return 0;
}
