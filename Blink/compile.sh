#!/bin/bash
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o bitwise.o bitwise.c
avr-gcc -mmcu=atmega328p bitwise.o -o bitwise
avr-objcopy -O ihex -R .eeprom bitwise bitwise.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:bitwise.hex
