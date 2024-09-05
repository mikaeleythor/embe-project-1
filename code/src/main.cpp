#include "encoder_driver.h"
#include <avr/delay.h>
#include <util/delay.h>

Encoder_driver encoder(1, 2);

int main () {
	encoder.init();
	while (1) {
		encoder.read_state();
		_delay_us(214);
	}
}
