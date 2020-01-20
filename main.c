#include <stdbool.h> // stellt "true" bereit
#include <stddef.h>
#include <avr/io.h> // stellt DDRB, PORTB und PIN5 bereit
#include <avr/interrupt.h>
#include <util/delay.h> // stellt _delay_ms bereit

// UART_BAUD ist im Makefile definiert
#define UBRR_BAUD ((F_CPU / (16 * (UART_BAUD))) - 1)

#if (UBRR_BAUD & ~0xFFF) != 0
  #error "Baud rate out of range!"
#endif

void uart_tx(char c)
{
  while((UCSR0A & (1<<UDRE0)) == 0); // warte darauf, dass wir senden dürfen
  UDR0 = c;
}

char uart_rx()
{
  while((UCSR0A & (1<<RXC0)) == 0); // warte auf empfangenes zeichen
  return UDR0;
}

void uart_tx_buf(char const * str, size_t length)
{
  while(length > 0) {
    uart_tx(*str);
    str += 1;
    length -= 1;
  }
}

int main()
{
  UCSR0A = 0; // Single Speed, Kein Multiprozessormodus
  UCSR0B = (1<<RXEN0) | (1<<TXEN0); // Sender und Empfänger anschalten
  UCSR0C =  (1<<UCSZ01) | (1<<UCSZ00); // 8N1
  UBRR0 = (UBRR_BAUD & 0xFFF); 

  // Schreibe einen String auf den Seriellport:
  char const text[] = "Hello, World!\r\n";
  uart_tx_buf(text, sizeof(text) - 1);

  while(true)
  {
    char c = uart_rx();
    uart_tx(c);
  }
}

