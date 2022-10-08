# Baremetal
Introduction to Arduino coding in C 

Hello, welcome in! This repository aims to document my progress and aventures in the world of embedded systems. As it just so happens, I have decided to learn the inner workings of the arduino UNO!

Prerequisite knowledge:
> A fundamental understanding of how base 2 works,
> A fundamental understanding of base 16,
> A decent grasp of the c programming langage, particularly a good understanding of pointers, type casting and compiler macros,
> Knowledge of bitwise operations and logic gates.

# Start
Okie dokie! we're off to the races then; my initial exposure to the topic at hand began at this article: https://create.arduino.cc/projecthub/milanistef/introduction-to-bare-metal-programming-in-arduino-uno-f3e2b4 
I highly reccomend reading it as it does provide a lot of valuable information.However, it left me with more questions than answers! Not to mention my confusion at the syntax being the first time I saw bitwise operators in use. 

# Operators
>* | - or
>* & - and
>* ^ - XOR (Exclusive or) 
>* ~ - Complement operator (inversion)
\
I found this article particularly helpful : https://www.programiz.com/c-programming/bitwise-operators 
# Schematic
Referring back to the first article I linked to; there is a schematic diagram shown of the arduino. Unforunately, I was not able to get a good view from 
the website provided. I reccomend visiting here instead for a larger image: https://electronicscheme.net/arduino-uno/arduino-uno-schematic/ simply click the image for an expanded view.
# Coding
Finally! Let's write some C; I will compare the code written in the tutorial given to what is in the BLINK folder:
* [ DDRB |= _BV(DDB5); ] All right let's break this syntax down; DDRB stands for "Data direction registry B". A register has a total of 8 bits that can be manipulated. In order to set physical pin13 as an output we need to flip the 5th bit of the register to 1. What about the "|="? This is just shorthand and is equivalent to : [ DDRB = DDRB _BV(DDB5); ] I assume if you've been coding for a while you're already familiar with shorthands in the form of +=, -= etc. The _BV(DDB5) part is a predefined compiler macro. It's defined as: #Define _BV(bit) (1 << (bit)). If you aren't familiar with #Define I suggest doing some additional research. I assume you've read the article on bitwise operations at this point and should understand how the |(OR),&(AND) and ~(Bitwise Complement/Inversion) work. So DDRB |= _BV(DDB5) is equivalent to: DDRB |= (1<<5);  
> I wanted to understand fully what was going on under the hood, so I did a bit more digging and found:
> volatile byte *DATADIRB = 0x24; This is the physical address in memory where DDRB is located on the ATMEGA328p. Please note at the beginning 
> of the file that "byte" is defined as an unsigned char. By default, char is defined as a signed integer in c, this means only 7 bits are available 
> In order make full use of the register we need an unsigned char type which allows us to manipulate all 8 bits in the register. If this is unclear feel free to do more research into signed/unsigned char and int types in c.
> *DATADIRB |= 1<<5; This should be fairly straightforward, simply flip the 5th bit ONLY at the memory located pointed to by DATADIRB. It's noteworthy 
> to recall that you are comparing whatever the current 8 states of the bits are in the register with whatever you shift with (1<<5). So for instance 
> if the initial state of the reg was 0010 1100, the comparision would look something like: 0010 1100 | 0011 1100 ; which would result in the fifth bit being turned on; 
> This can be shortened into : * ((volatile byte*) 0x24) |= 1<<5; Looks Scary I know, but fear not it's just scary at first sight.
> let's break it down, (volatile byte*) 0x24 - This is typcasting the defined data type "byte" as a pointer to the memory location 0x24. Just like if you were doing: char x = (char) a where a can be an int being typcasted into a char. So we typcast, then we dereference : *((xx*)0x24) then carry out the bitwise operation to flip the fifth bit. Finally, This bit of code is thrown into a #Define statement and hopefully you can read the code and sort the rest out yourself for portb as well.
> cont.
 

 Notes : /dev/ttyUSB* or /dev/ttyACM*
