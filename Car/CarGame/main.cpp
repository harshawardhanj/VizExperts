#include <iostream>
#include <Car.h>
#include <Engine.h>
#include <FerrariEngine.h>
#include <memory>
#include <thread>
#include <Logger.h>
 using namespace std;


/**
 * @brief During the development of "FerrariEngine" plugin, Engineer forgot include Car's Power along
 *        with timestamp in its Temperature Logging functionality.
 * @return
 */
int main()
{

    std::unique_ptr<Car> car(new Car("Ferrari"));

    std::unique_ptr<Engine> engine(new FerrariEngine());   //incomplete Engine,

    car->SetEngine(engine);

    //start Car simulation to record Engine Temperature for 10 sec.
    thread t(&Car::Simulate, car.get());

    t.join();

    return 0;
}
