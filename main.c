#include <stdbool.h> // stellt "true" bereit
#include <avr/io.h> // stellt DDRB, PORTB und PIN5 bereit
#include <util/delay.h> // stellt _delay_ms bereit

int main()
{
  DDRB = (1<<PIN5);
  while(true)
  {
    PORTB ^= (1<<PIN5);
    _delay_ms(500);
  }
}