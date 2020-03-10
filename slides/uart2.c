int main() {
  …

  UCSR0B |= (1<<RXCIE0); 

  sei();

  while(true);
}

ISR(USART_RX_vect) {
  UDR0 = UDR0;
}