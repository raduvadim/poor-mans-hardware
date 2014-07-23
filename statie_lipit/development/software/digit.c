/* Script afisare 7seg
 * 11/07/2014 vadim@home
 */
#include <avr/io.h>
#include <stdint.h>

#include "hardware.h"
//#include "spi.h"
#include "digit.h"

/* PB7 PB6 PB5 PB4 PB3 PB2 PB1 PB0
 *  A   B   C   D   E   F   G  DOT
 *   +----A----+
 *   |         |
 *   F         B
 *   |         |
 *   +----G----+
 *   |         |
 *   E         C
 *   |         |
 *   +----D----+  DOT
 * 
 * pinii sunt conectati pe considerente de catod comun
 */
//de modificat controlul in rev urmatoare
static uint8_t bcd_7seg[]= {0xFC, 0x60, 0xDC, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
void digit_print(uint8_t number){
	if(number > 9){
		DIGIT_PORT = 0x9E;
		return;
	}
	DIGIT_PORT = bcd_7seg[number];
} 
void digit_refresh(uint8_t nr1, uint8_t nr2, uint8_t nr3, uint8_t nr4){
	digit_print(nr1);
	//CATHODE_PORT=0; //primul segment 
	digit_print(nr2);
	//CATHODE_PORT=0; //primul segment 
	digit_print(nr3);
	//CATHODE_PORT=0; //primul segment 
	digit_print(nr4);
	//CATHODE_PORT=0; //primul segment 
}