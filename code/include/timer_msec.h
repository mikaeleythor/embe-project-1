#pragma once

class Timer_msec {
public:
  Timer_msec();
  void init(int period_ms, int duty_cycle);
  void set_duty_cycle(int duty_cycle);

private:
};
