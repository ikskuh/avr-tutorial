#include <stdbool.h> // stellt "true" bereit
#include <avr/io.h> // stellt DDRB, PORTB und PIN5 bereit
#include <avr/interrupt.h>
#include <util/delay.h> // stellt _delay_ms bereit

#define TIMER1_FREQ 2 // Hz
#define TIMER1_PRESC 1024
#define TIMER1_LIMIT (((F_CPU) / (TIMER1_PRESC)) / (TIMER1_FREQ) - 1)

int main()
{
  DDRB = (1<<PIN5); // Richtungsbit setzen PB5 = Output, der Rest ist Input
  
  // Setup des Timers
  TCCR1A = 0; // Keine PWM-Generation
  TCCR1B = (1<<CS12) | (1<<CS10) | (1<<WGM12); // Prescaler=1024,  CTC-Mode, TOP=OCR1A
  TCCR1C = 0;

  // Set the limit of the counter
  OCR1AH = (TIMER1_LIMIT >> 8) & 0xFF;
  OCR1AL = (TIMER1_LIMIT & 0xFF);

  TIMSK1 = (1<<OCIE1A); // Interrupt on compare match A

  sei(); // Interrupts an, hier beginnt es dann zu blinken
  
  // Ab jetzt: CPU dreht einfach nur einen Kreis und wartet auf Interrupts
  // Das Blinken passiert von selbst
  while(true);
}

// Definiert den Interrupt TIMER2 Compare A Match
ISR(TIMER1_COMPA_vect)
{
  // Wenn der Timer einen Compare Match hat, togglen wir die LED
  PORTB ^= (1<<PIN5);
}
