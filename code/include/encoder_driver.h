#include "digital_in.h"
#include "digital_out.h"
#include "timer_msec.h"

class Encoder_driver {
public:
  Encoder_driver(int c1, int c2);
  int position();
  void read_state();
	void init();

private:
	void blink();
private:
	Digital_out led;
  Digital_in position_encoder;
  Digital_in direction_encoder;
	int position_state; // State of position pin
  int position_value; // Diff in position since init
};
