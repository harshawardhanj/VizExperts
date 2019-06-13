#include "FerrariEngine.h"
#include <math.h>
#include <Logger.h>

FerrariEngine::FerrariEngine()
{
}

FerrariEngine::~FerrariEngine()
{
}

void FerrariEngine::Start()
{
}

void FerrariEngine::Gas(float amount)
{
     ApplyTorque(amount);
}

void FerrariEngine::Stop()
{
     //NA
}

size_t FerrariEngine::GetRPM() const
{
   return _rpm;
}

void FerrariEngine::LogEngineTemperature()
{
    LOG("Engine Temperature : "<<getEngineTemprature()<<" degrees");
}

void FerrariEngine::ApplyTorque(float amount)
{
      //Just assume these simple relations.
      _torque = _radius*amount;
      _rpm = amount*100*std::sqrt(amount);
      _power = _torque*_rpm;

      LogEngineTemperature();
}

float FerrariEngine::getEngineTemprature() const
{
    // Fake relation, just assume
   return  _rpm*4.5f;
}
