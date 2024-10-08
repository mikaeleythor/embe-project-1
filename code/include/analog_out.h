#ifndef ANALOG_OUT_H
#define ANALOG_OUT_H

#include <digital_out.h>
#include <timer_msec.h>

class Analog_out {
public:
  Analog_out(int pin_number);
  void init(int period_ms = 1000);
  void set(int duty_cycle);

private:
  Timer_msec timer;

public:
  Digital_out pin;
};

#endif // ANALOG_OUT_H
