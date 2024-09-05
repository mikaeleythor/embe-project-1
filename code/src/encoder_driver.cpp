#include "encoder_driver.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include <util/delay.h>

// #define PART3

Encoder_driver::Encoder_driver(int c1_, int c2_)
    : led(Digital_out(5)), position_encoder(Digital_in(c1_)),
      direction_encoder(Digital_in(c2_)), position_state(0), position_value(0),
      pulse_count(0) {}

void Encoder_driver::init() {
  led.init();

#ifdef PART3
  DDRD &= (1 << DDD1);
  PORTD |= (1 << PORTD2);
  EICRA |= (1 << ISC00);
  EIMSK |= (1 << INT0);
  sei();
#endif // PART3
}

void Encoder_driver::read_state() {
  bool new_position_state = position_encoder.is_hi(); // 1 if high, 0 if low

#ifdef PART1
  _delay_us(100);
#endif // PART1

  bool new_direction_state = direction_encoder.is_hi(); // 1 if high, 0 if low
  bool position_changed = new_position_state != position_state;
  if (position_changed) {
    // Increment pulse counter
    pulse_count++;
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

int Encoder_driver::position() { return position_value; }

int Encoder_driver::count() { return pulse_count; }
