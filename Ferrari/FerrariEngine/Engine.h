#ifndef ENGINE_H
#define ENGINE_H

#include <stddef.h>

class Engine
{
  public:

   virtual ~Engine(){};

   virtual void Start() = 0;
   virtual void Gas(float amount) = 0;
   virtual void Stop() = 0;

  protected:

    virtual size_t GetRPM() const = 0;
    virtual void ApplyTorque(float amount) = 0;
    virtual float getEngineTemprature() const = 0;

};


#endif // ENGINE_H
