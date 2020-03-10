#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

int main()
{
  DDRB = (1 << PIN5);
  while (true)
  {
    PORTB ^= (1 << PIN5);
    for (int i = 0; i < 5; i++)
      _delay_ms(200);
  }
}