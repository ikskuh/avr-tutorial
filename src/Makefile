# Generic config:
F_CPU=16000000     # CPU frequency
MCU=atmega328p     # AVR used
PORT?=/dev/ttyUSB0 # Which port does the programmer use
PROG?=arduino      # Which programmer to use
PROGBAUD?=57600    # What baud rate has the programmer
APPBAUD=19200      # What baud rate has our UART application

# Prepare compiler flags
DEFINES=F_CPU=$(F_CPU)ULL UART_BAUD=$(APPBAUD)ULL
FLAGS=-mmcu=$(MCU)
CFLAGS=$(FLAGS) $(addprefix -D,$(DEFINES)) -Os
LFLAGS=$(FLAGS)

CC=avr-gcc
LD=avr-gcc

all: blink1.elf blink2.elf uart1.elf uart2.elf
	avr-size --mcu=$(MCU) $^

hex: blink1.hex blink2.hex uart1.hex uart2.hex

clean:
	rm -f {blink1,blink2,uart1,uart2}.{o,hex,elf}

# Requires TARGET to be set
ifeq ($(strip $(TARGET)),)
flash:
	@echo "Please use one of the following:"
	@echo "make TARGET=blink1 flash"
	@echo "make TARGET=blink2 flash"
	@echo "make TARGET=uart1 flash"
	@echo "make TARGET=uart2 flash"
else
flash: $(TARGET).hex
	avrdude -P $(PORT) -c $(PROG) -b $(PROGBAUD) -p $(MCU) -e -U flash:w:$<
endif

# Start a terminal on the given port
terminal:
	picocom --baud $(APPBAUD) $(PORT)

# Map all programs directly to a .o file (and thus, to a .c file)
%.elf: %.o
	$(LD) $(LFLAGS) -o $@ $^

# Convert elf file into hex file
%.hex: %.elf
	avr-objcopy -O ihex $< $@

# Compiles a C file to an object file
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean flash init-vscode help hex terminal
.SUFFIXES: