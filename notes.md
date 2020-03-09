# Notes

## Arduino Blinky

```
Der Sketch verwendet 924 Bytes (3%) des Programmspeicherplatzes. Das Maximum sind 30720 Bytes.
Globale Variablen verwenden 9 Bytes (0%) des dynamischen Speichers, 2039 Bytes für lokale Variablen verbleiben. Das Maximum sind 2048 Bytes.
```

## Arduino Serial

```
Der Sketch verwendet 1488 Bytes (4%) des Programmspeicherplatzes. Das Maximum sind 30720 Bytes.
Globale Variablen verwenden 200 Bytes (9%) des dynamischen Speichers, 1848 Bytes für lokale Variablen verbleiben. Das Maximum sind 2048 Bytes.
```

## Comparison

```
   text    data     bss     dec     hex filename
    924       0       9     933     3a5 arduino-blink.elf
    236       0       0     236      ec blink1.elf
    198       0       0     198      c6 blink2.elf
```

```
   text    data     bss     dec     hex filename
   1454      34     166    1654     676 arduino-uart.elf
    306      16       0     322     142 uart1.elf
    322      16       0     338     152 uart2.elf
```

## Outline

- Wer bin ich?
- Worum gehts?
- Outline
- The Arduino way
    - Blink
    - Serial
- Pro/Contra
    - pro: Schnell zum Ziel
    - pro: Viele Beispiel
    - con: Arduino ist "fett"
    - con: Wir haben wenig Kontrolle
- Zum Ziel in vier Schritten
    - #1: Dokumentation lesen
    - #2: Code schreiben
    - #3: Compilen & Linken
    - #4: Flashen
- Warum tun wir uns das an?
    - Geschwindigkeit
    - Größe
    - Möglichkeiten
- #1: Dokumentation lesen
    - Welche Dokumente brauchen wir?
    - Schaltplan
    - Datenblatt
- #2: Code schreiben
    - Blink 1 / How to: Überhaupt
    - Blink 2 / How to: Datenblatt verwenden
    - UART 1 / How to: Hardware-Init
    - UART 2 / How to: Interrupt
- #3: Compilen & Linken
    - Was ist ein
        - Compiler?
        - Linker?
        - Bibliothek?
        - Makefile?
    - Dateiformate
        - elf object
        - elf executable
        - ihex
    - Tools
        - objdump
        - size
        - addr2line
- #4: Flashen
    - Möglichkeiten
        - High Voltage Serial Programming 
        - In-System Programming
        - Bootloader
    - Tools
        - avrdude
- Weiterführendes
    - Microcontroller.net
    - Roboternetz.de
    - Quellcode aus den Slides