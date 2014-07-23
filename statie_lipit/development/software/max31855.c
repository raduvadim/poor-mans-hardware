/*MAX31855
 * functii de interfatare
 */
#include <avr/io.h>
#include <stdint.h>

#include "hardware.h"
#include "max31855.h"
#include "spi.h"

/* MAX31855
 *vezi datasheet pentru informatii complete
 *intre timp. este nevoie de 4 citiri pentru un dump complet de informatii
 *inf sunt aranjate astfel:
 *|  nr bit  |31	   |  30 -> 18 |17   |16   |15	    | 14 -> 4	|3	  |2	|1	  |0	|
 *|----------+---------+-----------+-----+-----+--------+-----------+-----+-----+-----+-----+
 *|informatie|semn     |  temp tk  |don't|fault|semn    |temp       |don't|sc v+|sc v-| tk  |
 *|          |temp tk  |           |care |     |temp amb|ambientala |care |     |     |n/a  |
 *|31-----prima citire----24|23-a-doua-citire16|15-citire-nr-iii-8|7-----a patra citire-----|
 *
 *in functiile implementate nu se trateaza cazurile cu semn.
 *
 *
*/

uint16_t read_temperature(uint8_t option){
	SPI_PORT &= ~(1<<SPI_CS);
	uint32_t dump=((spi_byte_receive()<<24) | (spi_byte_receive()<<16) | (spi_byte_receive()<<8) | (spi_byte_receive()));
	SPI_PORT |= (1<<SPI_CS);
	 if (dump & 0x7) {
		 // uh oh, a serious problem!
		 return NAN;
	 }
	//cazul 0 returneaza temperatura termocuplei
	//cazul 1 returneaza temperatura ambientala
	//cazul 2 returneaza eroarea intalnita
	if(option == 0){
		dump >>= 18;
		
		//double centigrade = dump;
		// LSB = 0.25 degrees C
		//centigrade *= 0.25;
		
		return (uint16_t)(dump) & 0x7F;
	}
	if(option==1){
		//de implementat
	}
	if(option==2){
		//de implementat
	}
	return 0;
}