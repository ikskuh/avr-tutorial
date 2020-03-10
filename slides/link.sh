avr-ld \
  -mmcu=atmega328p \
  -o example.elf \
  -lm \
  example.o additional.o
