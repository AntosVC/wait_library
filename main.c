#include <avr/io.h>

#include "wait.h"

#define LEDS_ON   (1 << PB1) |(1 << PB0)
#define LEDS_OFF ~(1 << PB1) & ~(1 << PB0)

int main(void)
{

  DDRB |= (1 << PB1) | (1 << PB0);
  TCCR1B |= (1 << WGM12);

  while(1)
  {
    // Zmaiana stadnu diód led co 5s
    wait_s(5);
    PORTB |= LEDS_ON;
    wait_s(5);
    PORTB &= LEDS_OFF;
  }
}
