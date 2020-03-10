avr-gcc \
  -mmcu=atmega328p \
  -Os \
  -DF_CPU=16000000ULL \
  -o example.o \
  -c \
  example.c
