int main() {
  TCCR1A = 0; 
  TCCR1B = (1 << CS12) | (1 << CS10) | (1 << WGM12);
  TCCR1C = 0;

  OCR1AH = (TIMER1_LIMIT >> 8) & 0xFF;
  OCR1AL = (TIMER1_LIMIT & 0xFF);

  TIMSK1 = (1 << OCIE1A); 

  sei();
  while (true);
}
ISR(TIMER1_COMPA_vect) {
  PORTB ^= (1 << PIN5);
}
