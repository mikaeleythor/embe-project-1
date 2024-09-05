#include "analog_out.h"

Analog_out::Analog_out(int pin_number)
    : timer(Timer_msec()), pin(Digital_out(pin_number)) {}

void Analog_out::init(int period_ms) {
  timer.init(period_ms, 50);
  pin.init();
}

void Analog_out::set(int duty_cycle) { timer.set_duty_cycle(duty_cycle); }
