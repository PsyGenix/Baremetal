# Baremetal
Introduction to Arduino coding in C 

Hello, welcome in! This repository aims to document my progress and aventures in the world of embedded systems. As it just so happens, I have decided to learn the inner workings of the arduino UNO!

Prerequisite knowledge:
> A fundamental understanding of how base 2 works,
> A fundamental understanding of base 16,
> A decent grasp of the c programming langage, although I suppose one could follow along with minimal exposure;
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
* [ DDRB |= _BV(DDB5); ] All right let's break this syntax down; DDRB stands for "Data direction registry B". A register has a total of 8 bits that can be manipulated. In order to set physical pin13 as an output we need to flip the 5th bit of the register to 1. What about the "|="? This is just shorthand and is equivalent to : [ DDRB = DDRB _BV(DDB5); ] I assume if you've been coding for a while you're already familiar with shorthands in the form of +=, -= etc. The _BV(DDB5) part is a predefined compiler macro. It's defined as: #Define _BV(bit) (1 << (bit)). If you aren't familiar with #Define 
* To be cont.

 Notes : /dev/ttyUSB* or /dev/ttyACM*
