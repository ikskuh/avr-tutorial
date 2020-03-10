void uart_tx(char c) {
  while((UCSR0A & (1<<UDRE0)) == 0);
  UDR0 = c;
}
char uart_rx() {
  while((UCSR0A & (1<<RXC0)) == 0);
  return UDR0;
}

int main() {
  UCSR0A = 0;
  UCSR0B = (1<<RXEN0) | (1<<TXEN0);
  UCSR0C =  (1<<UCSZ01) | (1<<UCSZ00);
  UBRR0 = (UBRR_BAUD & 0xFFF); 

  while(true) {
    char c = uart_rx();
    uart_tx(c);
  }
}

