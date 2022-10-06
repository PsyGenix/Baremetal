#include <util/delay.h>
#include <avr/io.h>

typedef unsigned char byte; //assigns all 8 bits for use

#define DATA_DIR_REGB * ((volatile byte*) 0x24) 
#define CUST_PORT_B * ((volatile byte*) 0x25)  //compiler macros set

int main(int argc,char *argv[])
{
	
	//Build in LED is controlled by PORTB5 located on physical address 0x25
	/*
	 * volatile is used to override compiler optimzations(It might ignore declaration otherwise)
	 * volatile byte *DATADIRB = 0x24; //physical memory address of DDRB (DATA DIRECTION REGISTER)
	 * 		*DATADIRB |= 1<<5; //set as input 
	 * 		Alternative syntax >> 
	 *		* ((volatile byte*) 0x25) |= 1<<5; //DDRB bit 5 set as input
	 *		* ((volatile byte*) 0x24) |= 1<<5; //PORTB
	 * Typcasting, dereferencing and initializing 
	 */
	
	//Setup goes here
	DATA_DIR_REGB |= 1<<5; //DDR bit 5 set to high signalling pin to be used as input
	
	
	//loop
	while (1)
	{
		CUST_PORT_B |= 1<<5; //set bit 5 to high
		_delay_ms(1000); //1 second delay
		
		CUST_PORT_B &= ~(1<<5); //set bit 5 only to low
		_delay_ms(1000); //wait
	}
	
	return 0;
}
/* Compilation
 * avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o bitwise.o bitwise.c
 * avr-gcc -mmcu=atmega328p bitwise.o -o bitwise
 * avr-objcopy -O ihex -R .eeprom bitwise bitwise.hex
 * avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:bitwise.hex
 */

