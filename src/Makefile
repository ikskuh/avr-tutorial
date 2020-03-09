F_CPU=16000000
MCU=atmega328p
PORT?=/dev/ttyUSB0
PROG?=arduino
PROGBAUD?=57600
APPBAUD=19200

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

# This is just a fancy pants extra that will initialize your VSCode syntax highlighting and code completion
# if you have the C/C++ extension installed
init-vscode:
	mkdir -p .vscode

	echo '{"version":"2.0.0","tasks":[{"type":"shell","label":"build","command":"/usr/bin/make","args":[],"presentation":{"echo":false,"reveal":"silent","focus":false,"panel":"dedicated","showReuseMessage":false,"clear":true},"problemMatcher":"$$gcc","group":"build"},{"type":"shell","label":"flash","command":"/usr/bin/make","args":["flash"],"presentation":{"echo":false,"reveal":"always","focus":false,"panel":"dedicated","showReuseMessage":false,"clear":true},"problemMatcher":"$$gcc","group":"build"}]}' > .vscode/tasks.json

	echo '{"configurations":[{"name": "AVR","includePath":["/usr/avr/include"],"defines":[' > .vscode/c_cpp_properties.json
	avr-gcc $(CFLAGS) -c -dM -E - < /dev/null | grep -E '#define ([A-Za-z0-9_]+)[[:space:]]+([A-Za-z0-9\+\*\_]+)' | sort | sed -E 's/^#define ([A-Za-z0-9_]+)[[:space:]]+(.*)/"\1=\2",/' >> .vscode/c_cpp_properties.json
	echo '"_DUMMY_=0"],"compilerPath": "/usr/bin/avr-gcc","cStandard":"c99","cppStandard":"c++11","intelliSenseMode":"gcc-x86"}],"version":4}' >> .vscode/c_cpp_properties.json

.PHONY: clean flash init-vscode help hex terminal
.SUFFIXES: