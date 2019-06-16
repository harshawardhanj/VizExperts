#include "Car.h"
#include <ctime>
#include <chrono>
#include <thread>
#include <math.h>
#include <iostream>
#include "Logger.h"

using namespace std;

Car::Car(const std::string &name):_carName(name)
{

}

Car::~Car()
{

}

void Car::SetEngine(std::unique_ptr<UFerrariEngine> &engine)
{
    this->_engine = std::move(engine);
}

void Car::Simulate()
{

   clock_t start = clock(), elapsed=0;
   float gas=0;
   CLogger::GetLogger()->Log("");

   while(elapsed<=10)
   {
      int ss= clock()/ CLOCKS_PER_SEC;
      int mm=ss/60;
      ss=ss % 60;
      int hh=mm/60;
      mm=mm%60;

       string timestamp="";

       if(hh<10)
           timestamp="0"+std::to_string(hh);
       else
          timestamp=std::to_string(hh);

        if(mm<10)
           timestamp+=":0"+std::to_string(mm);
        else
            timestamp+=":"+std::to_string(mm);

        if(ss<10)
           timestamp+=":0"+std::to_string(ss);
        else
            timestamp+=":"+std::to_string(ss);

        LOGGER->Log(" %s Hp, %d", timestamp.c_str(),_engine->getPower() );
         cout<<timestamp<<",";
        cout<<" "<<_engine->getPower()<<" Hp,";
         _engine->Gas(std::sqrt(++gas));


       elapsed = (clock()-start)/CLOCKS_PER_SEC;


       std::this_thread::sleep_for(std::chrono::milliseconds(5));

   }

   }
