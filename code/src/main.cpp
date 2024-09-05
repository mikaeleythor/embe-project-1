#include "Arduino.h"
#include "encoder_driver.h"
#include <avr/delay.h>
#include <util/delay.h>

// #define PART1
// #define PART2
// #define PART3

Encoder_driver encoder(1, 2);

int main() {
  Serial.begin(9600);
  encoder.init();
  String print_str;
#ifdef PART1
  while (1) {
    for (int i = 0; i < 30000; i++) {
      encoder.read_state();
      _delay_us(281);
    }

    print_str = String(encoder.count());
    Serial.println(print_str);
  }
#endif // PART1
#ifdef PART2
  while (1) {
    encoder.read_state();
    _delay_us(281);
    print_str = String(encoder.count());
    Serial.println(print_str);
  }
#endif // PART2
#ifdef PART3
  while (1) {
    print_str = String(encoder.count());
    Serial.println(print_str);
    _delay_ms(3000);
  }
#endif // PART3
}

#ifdef PART3
ISR(INT0_vect) { encoder.read_state(); }
#endif // PART3
