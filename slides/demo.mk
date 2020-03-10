all: blink1.elf
	avr-size --mcu=$(MCU) $^

hex: blink1.hex

flash: blink.hex
	avrdude -P /dev/ttyUSB0 -c arduino -b 57600 -p atmega328p -e -U flash:w:$<

%.elf: %.o
	avr-ld -mmcu=atmega328p -o $@ -lm $^

%.hex: %.elf
	avr-objcopy -O ihex $< $@

%.o: %.c
	avr-gcc -mmcu=atmega328p -Os -o $@ -c $<

.PHONY: flash
.SUFFIXES: