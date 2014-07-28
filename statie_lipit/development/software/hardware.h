/*fisier: hardware.h
 * 11/07/2014 vadim@home
 * configurare pentru atmega8(TQFP 32pin)
 * pentru detalii consulta schema placii de control
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

// SPI			ATmega8	ATmega16	
#define SPI_PORT 		PORTB
#define SPI_PORT_DIR 	DDRB
#define SPI_SCK 		PB5
#define SPI_MISO 		PB4
#define SPI_MOSI 		PB3
#define SPI_CS			PB2

// USART
#define USART_U2X
#define BAUD 9600UL

// afisaj(4x7seg)
//#define DIGIT_PORT PORTC
//#define DIGIT_PORT_DIR DDRC
//#define CATHODE_PORT PORTB
//#define CATHODE_PORT_DIR DDRB

//Butoane input
//#define BUTTON_PORT PORTC
//#define BUTTON_PORT_DIR DDRC

#endif /* HARDWARE_H_ */
