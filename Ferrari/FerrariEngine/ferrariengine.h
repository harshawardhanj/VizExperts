#ifndef FERRARIENGINE_H
#define FERRARIENGINE_H

//#include "ferrariengine_global.h"
#include <Engine.h>

class __declspec(dllexport) FerrariEngine : public Engine
{

 public:
  FerrariEngine();
  ~FerrariEngine();

  virtual void Start();
  virtual void Gas(float amount);
  virtual void Stop();

 protected:

  virtual size_t GetRPM() const;

  virtual void ApplyTorque(float amount);

  virtual float getEngineTemprature() const;

  virtual void LogEngineTemperature();

  size_t _rpm;
  size_t _torque;
  size_t _radius;
  size_t _power;

};

#endif // FERRARIENGINE_H
