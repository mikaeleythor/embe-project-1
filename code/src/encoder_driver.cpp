#include "encoder_driver.h"
#include <util/delay.h>

Encoder_driver::Encoder_driver(int c1_, int c2_)
    : led(Digital_out(5)), position_encoder(Digital_in(c1_)),
      direction_encoder(Digital_in(c2_)), position_value(0) {}

void Encoder_driver::init() { led.init(); }

void Encoder_driver::read_state() {
  bool new_position_state = position_encoder.is_hi();   // 1 if high, 0 if low
	_delay_us(60);
  bool new_direction_state = direction_encoder.is_hi(); // 1 if high, 0 if low
  bool position_changed = new_position_state != position_state;
  if (position_changed) {
    // Define forward motion as direction and position states being at odds
    bool forward_motion = new_direction_state != new_position_state;
    if (forward_motion) {
      position_value++;
      blink();
    } else
      position_value--;
    position_state = new_position_state;
  }
}

void Encoder_driver::blink() {
  led.set_hi();
  led.set_lo();
  led.set_hi();
  led.set_lo();
  led.set_hi();
  led.set_lo();
}
