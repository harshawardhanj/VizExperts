#include "Car.h"
#include <ctime>
#include <chrono>
#include <thread>
#include <math.h>
#include <iostream>
using namespace std;

Car::Car(const std::string &name):_carName(name)
{

}

Car::~Car()
{

}

void Car::SetEngine(std::unique_ptr<Engine> &engine)
{
    this->_engine = std::move(engine);
}

void Car::Simulate()
{

   clock_t start = clock(), elapsed=0;
   float gas=0;

   while(elapsed<=10)
   {
      int ss= clock()/ CLOCKS_PER_SEC;
      int mm=ss/60;
      ss=ss % 60;
      int hh=mm/60;
      mm=mm%60;


       if(hh<10)
           cout<<"0"<<hh;
       else
          cout<<hh;

        if(mm<10)
           cout<<":0"<<mm;
        else
            cout<<":"<<mm;

        if(ss<10)
           cout<<":0"<<ss;
        else
            cout<<":"<<ss;


        _engine->Gas(std::sqrt(++gas));

        _engine->GetRPM();

       elapsed = (clock()-start)/CLOCKS_PER_SEC;


       std::this_thread::sleep_for(std::chrono::milliseconds(5));

   }

   }
